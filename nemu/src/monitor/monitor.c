/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/
#include <isa.h>
#include <memory/paddr.h>
#include <common.h>
#include <elf.h> 
#include <device/map.h> 

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm(const char *triple);

int func_num = 0; 

typedef struct {    
    char name[64];
    paddr_t addr;    
    Elf32_Xword size;
} Symbol;

Symbol *symbol = NULL;   


static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  //IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        //"to record the trace. This may lead to a large log file. "
        //"If it is not necessary, you can disable it in menuconfig")); 
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *elf_file = NULL;     
static char *img_file = NULL;
static int difftest_port = 1234;




/****************************************************************ftrace****************************************************************/
#ifdef CONFIG_FTRACE 

typedef struct {
    uint32_t   name_index;            //Elf32_Sym.st_name
    char       name[20];              //Elf32_Sym's name
    Elf32_Addr value;                 //Elf32_Sym.st_value
    uint32_t   size;                  //Elf32_Sym.st_size
}Func_Sym;

#define Is_FUNC(info)  ((ELF32_ST_TYPE(info)) == STT_FUNC)
#define MAX_func_size 32               //the max amount of FUNC symbols
static int func_amount = 0;            //FUNC symbol amount
static Func_Sym sym_fun_group[MAX_func_size] = {0};

static Elf32_Ehdr ELF_header = {0};     //ELF Header
static Elf32_Shdr symtab = {0};         //symbol table section
static Elf32_Shdr strtab = {0};         //string table section (containing name strings of symbols)
static Elf32_Sym sym_temp = {0};        //symbol temp

FILE *fp;                               //ELF FILE
static int sym_amount = 0;              //symbok amount
static char sym_name_buff[20] = {0};    //symbol name string temp


FILE *ftrace_log ;    // the log recording ftrace infomation
uint32_t loop = 0;    // the depth of calls
uint32_t check_func_interval(uint32_t pc)
{
  int i;
  for(i = 0; i < func_amount; i++)
  {
    uint32_t addr_s = sym_fun_group[i].value;
    uint32_t addr_e = sym_fun_group[i].value + sym_fun_group[i].size;
    if(addr_s <= pc && pc < addr_e)
      break;
  }
  assert(i < func_amount);
  return i;
}


// if the inst is ret, log the call
void RET_Log(uint32_t pc, uint32_t npc)
{
  // Log("s->pc:%x, s->dnpc:%x", pc, npc);
  loop--;
  //get the FUNC symbol index in sym_fun_group
  uint32_t index = check_func_interval(npc);   
  fprintf(ftrace_log, "[ftrace] 0x%08x: ", pc); 
  //print the certain amount of '  '
  for(int i=0; i<loop; i++)                           
    fprintf(ftrace_log, "  "); 
  fprintf(ftrace_log, "ret [%s]\n", sym_fun_group[index].name); 
  fflush(ftrace_log); 
}



// if the inst is jal or jalr(other than ret), log the call
void J_Log(uint32_t pc, uint32_t npc)
{
  // Log("s->pc:%x, s->dnpc:%x", pc, npc);
  //get the FUNC symbol index in sym_fun_group
  uint32_t index = check_func_interval(npc);
  fprintf(ftrace_log, "[ftrace] 0x%08x: ", pc); 
  //print the certain amount of '  '
  for(int i=0; i<loop; i++)
    fprintf(ftrace_log, "  "); 
  fprintf(ftrace_log, "call[%s@0x%08x]\n", sym_fun_group[index].name, sym_fun_group[index].value); 
  fflush(ftrace_log); 
  loop++;
}


//look up names of symbols in the strtab
static void Get_sym_name(uint32_t name_index, char *name)
{
  int i = 0;
  fseek(fp, (strtab.sh_offset + name_index), SEEK_SET);      //strtab.sh_offset is the start of string table (those strings are the names of symbols)
  int ret = fread((sym_name_buff + i), 1, 1, fp);  assert(ret == 1);
  i++;
  while(1)
  {
    ret = fread((sym_name_buff + i), 1, 1, fp);   assert(ret == 1);
    if(sym_name_buff[i++] == 0)   // == '.' in strtab
      break;
  }
  sym_name_buff[i-1] = '\0';     
  strcpy(name, sym_name_buff);
}

static void load_elf(void) {
  if (elf_file == NULL){
    Log("No ELF file is given.");
    return;
  }

  ftrace_log = fopen("./build/ftrace-log.txt", "w");
  assert(ftrace_log != NULL);

  fp = fopen(elf_file, "rb");
  Assert(fp, "Can not open '%s'", elf_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  Log("The ELF file is %s, size = %ld.", elf_file, size);
  fprintf(ftrace_log, "The ELF file is %s, size = %ld.\n", elf_file, size); 

  // ELF Header
  fseek(fp, 0, SEEK_SET); 
  int ret = fread(&ELF_header, sizeof(Elf32_Ehdr), 1, fp);  
  assert(ret == 1); 
  Log("Amount of section headers: %d.", ELF_header.e_shnum);
  Log("Start of section headers: 0x%x.", ELF_header.e_shoff);
  fprintf(ftrace_log, "Amount of section headers: %d.\n", ELF_header.e_shnum); 
  fprintf(ftrace_log, "Start of section headers: 0x%x.\n", ELF_header.e_shoff); 
  
  // symbol table
  fseek(fp, ELF_header.e_shoff + (ELF_header.e_shnum - 3) * sizeof(Elf32_Shdr), SEEK_SET); //symtab section in Section Headers
  ret = fread(&symtab, sizeof(Elf32_Shdr), 1, fp);
  assert(ret == 1);
  Log("Start of symtab: 0x%x", symtab.sh_offset);
  fprintf(ftrace_log, "Start of symtab: 0x%x\n", symtab.sh_offset); 
  sym_amount = symtab.sh_size / sizeof(Elf32_Sym);
  Log("The amount of symbol(s): %d", sym_amount);
  fprintf(ftrace_log, "The amount of symbol(s): %d\n", sym_amount); 

  //string table
  ret = fread(&strtab, sizeof(Elf32_Shdr), 1, fp);         //strtab section in Section Headers
  assert(ret == 1);
  Log("Start of strtab: 0x%x", strtab.sh_offset);     //name strings of symbols
  fprintf(ftrace_log, "Start of strtab: 0x%x\n", strtab.sh_offset); 

  // read every symbol to find FUNC symbol
  fseek(fp, symtab.sh_offset, SEEK_SET);                //Start of symbol table
  for(int i = 0; i < sym_amount; i++)
  {
    ret = fread(&sym_temp, sizeof(Elf32_Sym), 1, fp);
    assert(ret == 1);
    if(Is_FUNC(sym_temp.st_info))
    {
      sym_fun_group[func_amount].name_index = sym_temp.st_name;
      sym_fun_group[func_amount].size = sym_temp.st_size;
      sym_fun_group[func_amount].value = sym_temp.st_value;
      func_amount++;
    }
    assert(func_amount <= MAX_func_size);   // avoid sym_fun_group overflow
  }


  //get the name for every func symbol
  Log("Infomation about FUNC symbol(s):");
  fprintf(ftrace_log, "Infomation about FUNC symbol(s):\n"); 
  for(int i = 0; i < func_amount; i++)
  {
    Get_sym_name(sym_fun_group[i].name_index, sym_fun_group[i].name);
    printf(" \33[1;32m%-10s\33[0m   addr: 0x%08x   size: %d\n", sym_fun_group[i].name, sym_fun_group[i].value, sym_fun_group[i].size);
    fprintf(ftrace_log, " %-10s   addr: 0x%08x   size: %d\n", sym_fun_group[i].name, sym_fun_group[i].value, sym_fun_group[i].size); 
  }

  fprintf(ftrace_log, "\n\n");
  fflush(ftrace_log); 
  fclose(fp);
}


#endif
/**********************************************************************************************************/



static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {

  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"elf"      , required_argument, NULL, 'e'},    //////////
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'e': elf_file = optarg; break;     //////////
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-e,--elf=FILE           parse the elf file\n");     //////////////
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}


// void parse_elf(const char *elf_file);

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */
  
  /* Parse arguments. */
  parse_args(argc, argv);     //此函数给img_file赋值

  //printf("img_file = %s\n", img_file);    //////////////////////////

  // parse_elf(elf_file);   // ftrace

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

#ifdef CONFIG_FTRACE 
/* Load the ELF file of the image */
  load_elf();
#endif

  /* Initialize differential testing. */
  //printf("\n--------------------- diff_so_file = %s --------------------------\n",diff_so_file);
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE, init_disasm(
    MUXDEF(CONFIG_ISA_x86,     "i686",
    MUXDEF(CONFIG_ISA_mips32,  "mipsel",
    MUXDEF(CONFIG_ISA_riscv,
      MUXDEF(CONFIG_RV64,      "riscv64",
                               "riscv32"),
                               "bad"))) "-pc-linux-gnu"
  ));
#endif

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif



// ------------------------------------------------------ ftrace -------------------------------------------------------------------------------------
// void parse_elf(const char *elf_file)        //ELF 文件解析函数
// {
//     if(elf_file == NULL) {  ////检查输入参数是否为空
//       printf("@@@@@@@@@@@@    elf_file == NULL     @@@@@@@@@@@@\n");
//       return;        
//     }
//     // 打开ELF文件
//     FILE *fp = fopen(elf_file, "rb");   //rb只读
    
//     if(fp == NULL){                     //处理文件指针为空的情况
//         printf("failed to open the elf file!\n");
//         exit(0); 
//     }
//     Elf32_Ehdr ehdr;        //ELF文件头部 (ehdr, ELF Header),ehdr是 ELF文件的入口点，包含了整个ELF文件的基本信息和描述
// 	//读取ELF文件头Elf32_Ehdr信息
//     if(fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) <= 0){   //从fp指向的文件中读取1个Elf32_Ehdr大小的数据，并存入ehdr变量中，如果函数返回值小于等于0，说明读取失败
//         printf("fail to read the elf_head!\n");
//         exit(0);
//     }

//     //验证文件标识符是否符合 ELF 格式
//     if(ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || 
//        ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F'){
//         printf("The opened file isn't a elf file!\n");
//         exit(0);
//     }
    
//     fseek(fp, ehdr.e_shoff, SEEK_SET);  //把fp指针移动到离文件开头偏移量为ehdr.e_shoff的位置
//     //ehdr.e_shoff是一个整数字段，是节头部表的偏移地址，表示节头部表在文件中的位置，需要根据 e_shoff 的值来定位节头部表Section Header Table的位置
    
//     Elf32_Shdr shdr;    //节头部(shdr, Section Header),shdr包含了关于每个节（Section）的详细信息，如名称、大小、偏移量、类型等。
//     //每个 shdr 结构体对应一个节，描述了该节在文件中的位置、大小、属性和类型等
//     //ehdr 是 ELF 文件的头部, shdr 是 ELF 文件中每个节的头部

//     //寻找字符串表
//     char *string_table = NULL;      //字符串表指针
//     int i = 0;
//     for(i = 0; i < ehdr.e_shnum; i++){      //ehdr.e_shnum 表示节头部表的数量 ，通过 ehdr.e_shnum 来确定需要读取和处理多少个节头部表条目
//         if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0){  //从fp指向的文件中读取1个Elf32_Ehdr大小的数据，并存入shdr变量中，如果函数返回值小于等于0，说明读取失败
//             printf("fail to read the shdr\n");
//             exit(0);
//         }
        
//         if(shdr.sh_type == SHT_STRTAB){  //对应SHT_STRTAB类型---如果是字符串表节头部
//             //// 分配空间来存储字符串表，获取字符串表
//             string_table = malloc(shdr.sh_size);
//             fseek(fp, shdr.sh_offset, SEEK_SET);    //把fp文件指针移动到字符串表的偏移位置
//             if(fread(string_table, shdr.sh_size, 1, fp) <= 0)    //从fp指向的文件中读取字符串表大小的数据，并存入string_table指针指向处，如果函数返回值小于等于0，说明读取失败
//             {
//                 printf("fail to read the strtab\n");
//                 exit(0);
//             }
//         }
//     }

//     //遍历所有节头部表，寻找符号表
//     fseek(fp, ehdr.e_shoff, SEEK_SET);    //把fp文件指针移动到符号表的偏移位置
//     for(i = 0; i < ehdr.e_shnum; i++){    //ehdr.e_shnum 表示节头部表的数量 ，通过 ehdr.e_shnum 来确定需要读取和处理多少个节头部表条目
//         if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0){   //读取节头部表中的一个条目到shdr变量
//             printf("fail to read the shdr\n");
//             exit(0);
//         }

//         if(shdr.sh_type == SHT_SYMTAB){     //对应SHT_SYMTAB类型---如果是符号表节头部
//             fseek(fp, shdr.sh_offset, SEEK_SET);    //把fp文件指针移动到符号表的偏移位置

//             Elf32_Sym sym;  

//             size_t sym_count = shdr.sh_size / shdr.sh_entsize;  //// 计算符号表条目的数量
//             symbol = malloc(sizeof(Symbol) * sym_count);    //// 分配空间来存储符号信息的数组
//             size_t j = 0;
//             for(j = 0; j < sym_count; j++){     //符号表条目的数量作为循环数
//                 if(fread(&sym, sizeof(Elf32_Sym), 1, fp) <= 0){     //读取符号表中的一个条目到sym变量
//                     printf("fail to read the symtab\n");
//                     exit(0);
//                 }

//                 if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC){     //对应STT_FUNC类型---如果是函数符号
//                     const char *name = string_table + sym.st_name;  // 获取函数名，通过字符串表和符号表的索引计算得到
//                     strncpy(symbol[func_num].name, name, sizeof(symbol[func_num].name) - 1);    // 将函数名复制到符号信息数组symbol中
//                     symbol[func_num].addr = sym.st_value;   // 存储函数地址
//                     symbol[func_num].size = sym.st_size;    // 存储函数大小
//                     func_num++; //增加函数计数器
//                 }
//             }
//         }
//     }
//     fclose(fp);
//     free(string_table);   //释放字符串表所占用的内存空间
//     return;
// }



// int rec_depth = 1;
// void display_call_func(word_t pc, word_t func_addr)
// {
//     int i = 0;
//     for(; i < func_num; i++){
//         if(func_addr >= symbol[i].addr && func_addr < (symbol[i].addr + symbol[i].size)){
//             break;
//         }
//     }
//     printf("0x%08x:", pc);
//     //int k = 0;
//     //for(k = 0; k < rec_depth; k++) printf("  ");

//     //rec_depth++;

//     printf("  call  [%s@0x%08x]\n", symbol[i].name, func_addr);
//     return;
// }



// void display_ret_func(word_t pc)
// {
//     int i = 0;
//     for(; i < func_num; i++){
//         if(pc >= symbol[i].addr && pc < (symbol[i].addr + symbol[i].size)){
//             break;
//         }
//     }
//     printf("0x%08x:", pc);
//     //rec_depth--;
//     //int k = 0;
//     //for(k = 0; k < rec_depth; k++) printf("  ");
//     printf("  ret   [%s]\n", symbol[i].name);
//     return;
// }
// ------------------------------------------------------ ftrace -------------------------------------------------------------------------------------
