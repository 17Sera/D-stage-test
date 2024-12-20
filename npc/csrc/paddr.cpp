// #include "../include/paddr.h"
// #include "Vysyx_23060219.h"
// #include "Vysyx_23060219___024root.h"


// /********extern functions or variables********/
// extern Vysyx_23060219 *top;
// extern vluint64_t main_time;
// extern void close_tfp(void);
// /*********************************************/



// uint8_t pmem[PMEM_SIZE] PG_ALIGN = {};
// static const word_t img [] = {
//   //0x06400593,    //li	  a1,100
//   0x06458613,    //addi	a2,a1,100
//   0x0c860693,    //addi	a3,a2,200
//   0xed468713,    //addi	a4,a3,-300
//   0x30571073,    //csrw	mtvec,a4
//   0xe7070793,    //addi	a5,a4,-400
//   0x80178813,    //addi	a6,a5,-2047
//   0x7fa80893,    //addi	a7,a6,2042
//   0x7fa88893,    //addi	a7,a7,2042

//   // 0x0007a783,    //lw	a5,0(a5)

//   // 0x00f12423,    //sw	a5,8(sp)

//   0x00100073,    //ebreak
//   // 0x06458613,    //addi	a2,a1,100
//   // 0x0c860693,    //addi	a3,a2,200
//   // 0x00000297,    // auipc t0,0
//   // 0x00000513,    //	li	a0,0
//   // 0x00100073,    // ebreak 
//   // 0xdeadbeef,    // some data
// };



// uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - PMEM_BASE; }   //0x8000_0000 -> pmem[0]
// paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + PMEM_BASE; }


// word_t host_read(void *addr, int len) 
// {
//   switch (len) {
//     case 1: return *(uint8_t  *)addr;
//     case 2: return *(uint16_t *)addr;
//     case 4: return *(uint32_t *)addr;
//     // case 8: return *(uint64_t *)addr;
//     default: assert(0); return 0;
//   }
// }

// static void host_write(void *addr, int len, word_t data) {
//   switch (len) {
//     case 1: *(uint8_t  *)addr = data; return;
//     case 2: *(uint16_t *)addr = data; return;
//     case 4: *(uint32_t *)addr = data; return;
//     // case 8: *(uint64_t *)addr = data; return;
//     default: assert(0);
//   }
// }

// static inline bool in_pmem(paddr_t addr) {
//   return (addr - PMEM_BASE < PMEM_SIZE);
// }

// static inline void out_of_bound(paddr_t addr) {
//   close_tfp();
//   panic("address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld", 
//          addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyx_23060219__DOT__bru_inst__DOT__npc_reg, main_time);
// }

// word_t pmem_r(paddr_t addr, int len) 
// {
//   if(in_pmem(addr))   //check if within the bound
// #ifdef CONFIG_MTRACE
//   {
//     word_t data = host_read(guest_to_host(addr), len);
//     _Log(ANSI_FG_YELLOW "[mtrace]" ANSI_NONE " rd_mem  " ANSI_FG_YELLOW 
//         "addr:" ANSI_NONE " 0x%08x  " ANSI_FG_YELLOW "data:" 
//         ANSI_NONE " 0x%08x\n", addr, data);
//     return data;
//   }
// #else
//     return host_read(guest_to_host(addr), len);
// #endif

//   out_of_bound(addr);
//   return 0;
// }

// void pmem_w(paddr_t addr, int len, word_t data) 
// {
//   if(in_pmem(addr))   //check if within the bound
//   {
// #ifdef CONFIG_MTRACE
//     _Log(ANSI_FG_YELLOW "[mtrace]" ANSI_NONE " wr_mem  " ANSI_FG_YELLOW 
//     "addr:" ANSI_NONE " 0x%08x  " ANSI_FG_YELLOW "data:" 
//     ANSI_NONE " 0x%08x\n", addr, data);
// #endif
//     host_write(guest_to_host(addr), len, data);
//     return;
//   }  

//   out_of_bound(addr);
// }

// void init_mem(void) 
// {
//   memset(pmem, 0, PMEM_SIZE);
//   Log("physical memory area [0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);

//   /* Load built-in image. */
//   memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
// }

//=====================================================================================================
//SOC

#include "../include/paddr.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull.h"


/********extern functions or variables********/
extern VysyxSoCFull      *top;
extern vluint64_t main_time;
extern void close_tfp(void);
/*********************************************/
uint8_t pmem[PMEM_SIZE] PG_ALIGN = {};
uint8_t mrom[MROM_SIZE] PG_ALIGN = {};
static const word_t img [] = {
  //0x06400593,    //li	  a1,100
  //0x00100073,    //ebreak
  //0x01012783,        //  	lw	a5,16(sp)
  0x06458613,    //addi	a2,a1,100
  0x0c860693,    //addi	a3,a2,200
  0xed468713,    //addi	a4,a3,-300
  0x30571073,    //csrw	mtvec,a4
  0xe7070793,    //addi	a5,a4,-400
  0x80178813,    //addi	a6,a5,-2047
  0x7fa80893,    //addi	a7,a6,2042
  0x7fa88893,    //addi	a7,a7,2042
  0x00100073,    //ebreak
  // 0x06458613,    //addi	a2,a1,100
//   0x0c860693,    //addi	a3,a2,200
//   0x00000297,    // auipc t0,0
//   0x00000513,    //	li	a0,0
//   0x00100073,    // ebreak 
//   0xdeadbeef,    // some data
};

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data)
{ 
    assert(data != NULL); // 确保 data 指针不为空
    assert(addr >= MROM_BASE && addr < MROM_BASE + MROM_SIZE); // 地址合法性检查

    uint32_t offset = ((addr & 0xfffffffc) - MROM_BASE);
    *data = *((uint32_t *)(mrom + offset));

    // *data = 0x00100073;   // 测试mrom，输入ebreak指令
}

uint8_t* mrom_guest_to_host(paddr_t paddr) { return mrom + paddr - MROM_BASE; }   

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - PMEM_BASE; }   //0x8000_0000 -> pmem[0]

paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + PMEM_BASE; }


word_t host_read(void *addr, int len) 
{
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    // case 8: return *(uint64_t *)addr;
    default: assert(0); return 0;
  }
}

static void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    // case 8: *(uint64_t *)addr = data; return;
    default: assert(0);
  }
}

static inline bool in_pmem(paddr_t addr) {
  return (addr - PMEM_BASE < PMEM_SIZE);
}

static inline void out_of_bound(paddr_t addr) {
  close_tfp();
  //npc_state.state = NPC_END;
  panic("address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld", 
         addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bru_inst__DOT__npc_reg, main_time);
}

word_t pmem_r(paddr_t addr, int len) 
{
  if(in_pmem(addr))   //check if within the bound
#ifdef CONFIG_MTRACE
  {
    word_t data = host_read(guest_to_host(addr), len);
    _Log(ANSI_FG_YELLOW "[mtrace]" ANSI_NONE " rd_mem  " ANSI_FG_YELLOW 
        "addr:" ANSI_NONE " 0x%08x  " ANSI_FG_YELLOW "data:" 
        ANSI_NONE " 0x%08x\n", addr, data);
    return data;
  }
#else
    return host_read(guest_to_host(addr), len);
#endif
  out_of_bound(addr);
  return 0;
}

int pmem_read(int addr) {
    //printf("read    addr:0x%x, len:4\n", addr);
    int ret = host_read(guest_to_host(addr), 4);
    return ret;
}

void pmem_w(paddr_t addr, int len, word_t data) 
{
  if(in_pmem(addr))   //check if within the bound
  {
#ifdef CONFIG_MTRACE
    _Log(ANSI_FG_YELLOW "[mtrace]" ANSI_NONE " wr_mem  " ANSI_FG_YELLOW 
    "addr:" ANSI_NONE " 0x%08x  " ANSI_FG_YELLOW "data:" 
    ANSI_NONE " 0x%08x\n", addr, data);
#endif
    host_write(guest_to_host(addr), len, data);
    return;
  }  

  out_of_bound(addr);
}

void init_mem(void) 
{
  memset(mrom, 0, MROM_SIZE);
  // memset(pmem, 0, PMEM_SIZE); //将pmem物理内存的所有字节设置为0，pmem指向物理内存的起始地址，PMEM_SIZE为要填充的内存区域大小
  // Log("physical memory area [0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT); //记录物理内存区域边界
    Log("mrom memory area [0x%08x, 0x%08x]", MROM_BASE, MROM_BASE+MROM_SIZE-1); //记录物理内存区域边界

  /* Load built-in image. */
  memcpy(mrom_guest_to_host(MROM_BASE), img, sizeof(img));  //将内置镜像img的内容复制到物理内存中的启动位置
  // memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));  //将内置镜像img的内容复制到物理内存中的启动位置

  //guest_to_hoat(RESET_VECTOR)：返回指向物理内存中RESET_VECTOR位置的指针，是程序的起始位置
}