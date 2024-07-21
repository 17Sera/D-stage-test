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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

static char *regname[] = {            ///////////////
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool diff = true;
  int i = 0;
  for(i = 0; i < 32; i++){
    if(cpu.gpr[i] != ref_r->gpr[i]){    //循环比较通用寄存器
      diff = false;
      break;
    }
  }
  //if((diff = true) && cpu.pc == ref_r->pc){      //检查PC
  if(diff){           //不检查PC，检查的话不出结果，只触发isa_reg_display()
    return true;
  }

  //pc = ref_r->pc;     //上述条件未满足，将 pc 更新为 ref_r->pc
  return false;
}


void isa_difftest_attach(CPU_state *ref_r) {    /////触发difftest 用于difftest显示寄存器值
  int i = 0;
  for( i = 0; i < 10; i++ ){
    if(cpu.gpr[i] != ref_r->gpr[i])
		  printf("[difftest] gpr i: %d     DUT val:  $%s = 0x%08x  REF val: $%s = 0x%08x  <------- \n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
    else
		  printf("[difftest] gpr i: %d     DUT val:  $%s = 0x%08x  REF val: $%s = 0x%08x\n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
  }

  for( i = 10; i < 26; i++ ){
    if(cpu.gpr[i] != ref_r->gpr[i])
		  printf("[difftest] gpr i: %d    DUT val:  $%s = 0x%08x  REF val: $%s = 0x%08x  <------- \n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
    else
		  printf("[difftest] gpr i: %d    DUT val:  $%s = 0x%08x  REF val: $%s = 0x%08x\n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
  }

  for( i = 26; i < 28; i++ ){
    if(cpu.gpr[i] != ref_r->gpr[i])
		  printf("[difftest] gpr i: %d    DUT val:  $%s= 0x%08x  REF val: $%s= 0x%08x  <------- \n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
    else
		  printf("[difftest] gpr i: %d    DUT val:  $%s= 0x%08x  REF val: $%s= 0x%08x\n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
  }

    for( i = 28; i < 32; i++ ){
    if(cpu.gpr[i] != ref_r->gpr[i])
		  printf("[difftest] gpr i: %d    DUT val:  $%s = 0x%08x  REF val: $%s = 0x%08x  <------- \n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
    else
		  printf("[difftest] gpr i: %d    DUT val:  $%s = 0x%08x  REF val: $%s = 0x%08x\n", i, regname[i], cpu.gpr[i], regname[i], ref_r->gpr[i] );
  }

}
