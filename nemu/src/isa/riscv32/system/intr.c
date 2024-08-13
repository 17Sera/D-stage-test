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

word_t isa_raise_intr(word_t NO, vaddr_t epc) {   //模拟触发异常后硬件的响应过程
  // cpu.csr.mcause = NO;    // NO对应异常种类

  cpu.csr.mcause = 0xb;   // 在mcause寄存器中设置异常号
  cpu.csr.mepc = epc;     // epc对应触发异常的指令地址，将当前PC值保存到mepc寄存器

#ifdef CONFIG_ETRACE
  printf("\33[1;33m[Etrace] \33[0m \33[1;33mmstatus:\33[0m 0x%x    "
         "\33[1;33  mmepc:\33[0m 0x%x    \33[1;33  mmcause:\33[0m 0x%x\n", 
          cpu.csr.mstatus, cpu.csr.mepc, cpu.csr.mcause);
  log_write ("[Etrace] mstatus: 0x%08x, mepc: 0x%08x, mcause: 0x%08x\n", 
              cpu.csr.mstatus, cpu.csr.mepc, cpu.csr.mcause);
#endif


  return cpu.csr.mtvec;   // 从mtvec寄存器中取出异常入口地址

}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
