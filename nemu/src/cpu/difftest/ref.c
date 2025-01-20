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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

#define SRAM_BASE   0x0f000000
#define SRAM_SIZE   0x1000000

#define FLASH_BASE  0x30000000
#define FLASH_SIZE  0x10000000


__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) 
{
  if (addr >= FLASH_BASE && addr < FLASH_BASE + FLASH_SIZE){      // flash
    if (direction == DIFFTEST_TO_DUT) {
      for (int i = 0; i < n; i++) {
        *((uint8_t *)(buf) + i) = *guest_to_host(addr + i);
      }
    } else {
      for (int i = 0; i < n; i++) {
        *guest_to_host(addr + i) = *((uint8_t *)(buf) + i);
      }
    }
  }
  else if (addr >= SRAM_BASE && addr < SRAM_BASE + SRAM_SIZE) {   // sram
    if (direction == DIFFTEST_TO_DUT) {
      for (int i = 0; i < n; i++) {
        *((uint8_t *)(buf) + i) = *guest_to_host(addr + i);
      }
    } else {
      for (int i = 0; i < n; i++) {
        *guest_to_host(addr + i) = *((uint8_t *)(buf) + i);
      }
    }
  }
  else
    assert(0);
}



__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if(direction == DIFFTEST_TO_REF)
    memcpy(&cpu, dut, sizeof(cpu));
  else if(direction == DIFFTEST_TO_DUT)
    memcpy(dut, &cpu, sizeof(cpu));
  else
    assert(0);
}



__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}



__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}



__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
