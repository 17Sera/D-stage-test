/*#include <common.h>
#include <elf.h>
#include <device/map.h>

int func_num = 0;
const char *elf_file = 0;

typedef struct {
    char name[64];
    paddr_t addr;    
    Elf32_Xword size;
} Symbol;

Symbol *symbol = NULL; 

void parse_elf(const char *elf_file)
{
    if(elf_file == NULL) return;
    
    FILE *fp;
    fp = fopen(elf_file, "rb"); //打开指定的 ELF 文件
    
    if(fp == NULL)
    {
        printf("failed to open the elf file!\n");
        exit(0);
    }
	
    Elf32_Ehdr edhr;
	//读取elf头
    if(fread(&edhr, sizeof(Elf32_Ehdr), 1, fp) <= 0)    //读取文件头 Elf32_Ehdr
    {
        printf("fail to read the elf_head!\n");
        exit(0);
    }

    if(edhr.e_ident[0] != 0x7f || edhr.e_ident[1] != 'E' || //验证文件标识符是否符合 ELF 格式
       edhr.e_ident[2] != 'L' ||edhr.e_ident[3] != 'F')
    {
        printf("The opened file isn't a elf file!\n");
        exit(0);
    }
    
    fseek(fp, edhr.e_shoff, SEEK_SET);  //将文件指针fp移动到节头部表的偏移位置，偏移量为edhr.e_shoff

    Elf32_Shdr shdr;
    char *string_table = NULL;
    //寻找字符串表
    int i = 0;
    for(i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }
        
        if(shdr.sh_type == SHT_STRTAB)  //对应节头部表中的SHT_STRTAB类型
        {
            //获取字符串表
            string_table = malloc(shdr.sh_size);
            fseek(fp, shdr.sh_offset, SEEK_SET);
            if(fread(string_table, shdr.sh_size, 1, fp) <= 0)
            {
                printf("fail to read the strtab\n");
                exit(0);
            }
        }
    }

    //寻找符号表
    fseek(fp, edhr.e_shoff, SEEK_SET);
    int i = 0;
    for(i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }

        if(shdr.sh_type == SHT_SYMTAB)
        {
            fseek(fp, shdr.sh_offset, SEEK_SET);

            Elf32_Sym sym;

            size_t sym_count = shdr.sh_size / shdr.sh_entsize;
            symbol = malloc(sizeof(Symbol) * sym_count);
            size_t j = 0;
            for(j = 0; j < sym_count; j++)
            {
                if(fread(&sym, sizeof(Elf32_Sym), 1, fp) <= 0)
                {
                    printf("fail to read the symtab\n");
                    exit(0);
                }

                if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC)
                {
                    const char *name = string_table + sym.st_name;
                    strncpy(symbol[func_num].name, name, sizeof(symbol[func_num].name) - 1);
                    symbol[func_num].addr = sym.st_value;
                    symbol[func_num].size = sym.st_size;
                    func_num++;
                }
            }
        }
    }
    fclose(fp);
    free(string_table);
}



int rec_depth = 1;
void display_call_func(word_t pc, word_t func_addr)
{
    int i = 0;
    for(; i < func_num; i++){
        if(func_addr >= symbol[i].addr && func_addr < (symbol[i].addr + symbol[i].size)){
            break;
        }
    }
    printf("0x%08x:", pc);
    int k = 0;
    for(k = 0; k < rec_depth; k++) printf("  ");

    rec_depth++;

    printf("call  [%s@0x%08x]\n", symbol[i].name, func_addr);
}

void display_ret_func(word_t pc)
{
    int i = 0;
    for(; i < func_num; i++){
        if(pc >= symbol[i].addr && pc < (symbol[i].addr + symbol[i].size)){
            break;
        }
    }
    printf("0x%08x:", pc);
    rec_depth--;
    int k = 0;
    for(k = 0; k < rec_depth; k++) printf("  ");
    printf("ret  [%s]\n", symbol[i].name);
}
*/