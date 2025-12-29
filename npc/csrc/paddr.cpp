#include "../include/paddr.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull.h"

/*-----------------------------------------------*/
extern VysyxSoCFull      *top;
extern vluint64_t         main_time;
extern void close_tfp    (void);
/*-----------------------------------------------*/

uint8_t   pmem   [PMEM_SIZE]   PG_ALIGN = {};
uint8_t   mrom   [MROM_SIZE]   PG_ALIGN = {};
uint8_t   flash  [FLASH_SIZE]  PG_ALIGN = {};
uint8_t   sram   [SRAM_SIZE]   PG_ALIGN = {};

/*-----------------------------------------------*/

static const word_t img [] = {
  // char-test inst test flash
    0x100007b7,     
    0x04100713,      
    0x00e78023,     
    0x04200713,      
    0x00e78023,      
    0x0000006f,   

    // 0x00100073,    // ebreak 
};

/*---------------------------------------------------------------------------------------------*/

extern "C" void flash_read(int32_t addr, int32_t *data) { 
  if (addr < 0 || addr >= FLASH_SIZE) {                 // 偏移量边界检查
    fprintf(stderr, "Error: Address out of bounds\n");
    return;
  }

  if (addr % 4 != 0) {                                  // 检查是否4字节对齐
    fprintf(stderr, "Error: Address not aligned\n");
    return;
  }

  *data = ( (uint32_t*) flash )  [ addr / 4 ];          // 读取flash数据
  // fprintf(stderr, "Flash read addr: 0x%x      flash read data: 0x%x\n",  addr + FLASH_BASE, *data);
}



extern "C" void mrom_read(int32_t addr, int32_t *data)
{ 
    assert(data != NULL); // 确保 data 指针不为空
    assert(addr >= MROM_BASE && addr < MROM_BASE + MROM_SIZE); // 地址合法性检查

    uint32_t offset = ((addr & 0xfffffffc) - MROM_BASE);
    *data = *((uint32_t *)(mrom + offset));

    // *data = 0x00100073;   // 测试mrom，输入ebreak指令
}

/*--------------------------------------------------------------------------------------------*/

uint8_t*   sram_guest_to_host  (paddr_t paddr)  { return sram  + paddr -  SRAM_BASE; }   
uint8_t*   flash_guest_to_host (paddr_t paddr)  { return flash + paddr - FLASH_BASE; }   
uint8_t*   mrom_guest_to_host  (paddr_t paddr)  { return mrom  + paddr -  MROM_BASE; }   
uint8_t*   guest_to_host       (paddr_t paddr)  { return pmem  + paddr -  PMEM_BASE; }   //0x8000_0000 -> pmem[0]
paddr_t    host_to_guest       (uint8_t *haddr) { return haddr - pmem  +  PMEM_BASE; }

/*--------------------------------------------------------------------------------------------*/

word_t host_read(void *addr, int len) 
{
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0); return 0;
  }
}


static void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: assert(0);
  }
}


static inline bool in_pmem(paddr_t addr) {
  return (addr - PMEM_BASE < PMEM_SIZE);
}


static inline void out_of_bound(paddr_t addr) {
  close_tfp();
  panic("address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld", 
         addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__PC, main_time);
}


word_t pmem_r(paddr_t addr, int len) 
{
  if(in_pmem(addr))  
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
    int ret = host_read(guest_to_host(addr), 4);
    return ret;
}


void pmem_w(paddr_t addr, int len, word_t data) 
{
  if(in_pmem(addr)) 
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

/*--------------------------------------------------------------------------------------------------------------------------*/

void init_mem(void)   
{
/**** flash ****/
  memset(flash, 0, FLASH_SIZE);
  Log("flash memory area [0x%08x, 0x%08x]", FLASH_BASE, FLASH_BASE + FLASH_SIZE - 1 ); 
  /* Load built-in image. */
  memcpy(flash_guest_to_host(FLASH_BASE), img, sizeof(img));  // 加载内置镜像到内存


/**** mrom ****/
  // memset(mrom, 0, MROM_SIZE);
  // Log("mrom memory area [0x%08x, 0x%08x]", MROM_BASE, MROM_BASE + MROM_SIZE); 
  // /* Load built-in image. */
  // memcpy(mrom_guest_to_host(MROM_BASE), img, sizeof(img));  // 加载内置镜像到内存
}
