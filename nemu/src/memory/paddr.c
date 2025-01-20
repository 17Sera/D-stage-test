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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

/*------------------------------------------------------------------------------------------------------*/

static uint8_t  flash  [CONFIG_MSIZE] PG_ALIGN = {};  
static uint8_t  sram  [0x1000000]    PG_ALIGN = {};

// /*------------------------------------------------------------------------------------------------------*/

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of flash [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

// /*------------------------------------------------------------------------------------------------------*/

paddr_t host_to_guest(uint8_t *haddr) { return haddr - flash + CONFIG_MBASE; }


uint8_t* guest_to_host(paddr_t paddr) {
  if     ( paddr >= 0x0f000000 && paddr <= 0x0fffffff ) { return sram + paddr - 0x0f000000;}  
  else if( paddr >= 0x30000000 && paddr <= 0x3fffffff ) { return flash + paddr - 0x30000000;}  // flash
  else   {
    out_of_bound(paddr);
    assert(0);
  }
}

// /*------------------------------------------------------------------------------------------------------*/

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

// /*------------------------------------------------------------------------------------------------------*/

void init_mem() {
  IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), CONFIG_MSIZE));
  IFDEF(CONFIG_MEM_RANDOM, memset(sram ,   0  , 0x1000000   ));
}

// /*------------------------------------------------------------------------------------------------------*/

word_t paddr_read(paddr_t addr, int len) {
  if(likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}


void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}







// ***********  save  ****************************************************************************

// void init_mem() {
//   IFDEF(CONFIG_MEM_RANDOM, memset(sram ,   0   , 8*1024      ));
//   // IFDEF(CONFIG_MEM_RANDOM, memset(mrom , rand(), 4*1024      ));
//   IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), 16*1024*1024));
//   // IFDEF(CONFIG_MEM_RANDOM, memset(psram, 0, 4*1024*1024));
//   // IFDEF(CONFIG_MEM_RANDOM, memset(sdram, 0, 64*1024*1024));
//   // Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
// }

// void init_mem() {
//   IFDEF(CONFIG_MEM_RANDOM, memset(sram, 0, 0xffffff));
//   IFDEF(CONFIG_MEM_RANDOM, memset(mrom, rand(), 0xfff));
//   IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), 0xfffffff));
//   IFDEF(CONFIG_MEM_RANDOM, memset(psram, 0, 0x1fffffff));
//   IFDEF(CONFIG_MEM_RANDOM, memset(sdram, 0, 0x1fffffff));
// }


// uint8_t* guest_to_host(paddr_t paddr) {
//   if     ( paddr >= 0x0f000000 && paddr <= 0x0fffffff ) { return sram  + paddr  - 0x0f000000;} 
//   // else if( paddr >= 0x20000000 && paddr <= 0x20000fff ) { return mrom  + paddr  - 0x20000000;}
//   else if( paddr >= 0x30000000 && paddr <= 0x3fffffff ) { return flash + paddr  - 0x30000000;} 
//   // else if( paddr >= 0x80000000 && paddr <= 0x9fffffff ) { return psram + paddr - 0x80000000;} 
//   // else if( paddr >= 0xa0000000 && paddr <= 0xbfffffff ) { return sdram + paddr - 0xa0000000;} 
//   else {
//     out_of_bound(paddr);
//     assert(0);
//   }
// }