#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vysyx_23060219_top.h"
#include "verilated_fst_c.h"
#include "Vysyx_23060219_top__Dpi.h"
#include "svdpi.h"
#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"


VerilatedFstC *tfp = new VerilatedFstC(); //导出fst波形需要加此语句
Vysyx_23060219_top *top = new Vysyx_23060219_top("top");
vluint64_t    main_time = 0;  //initial 仿真时间



/********extern functions or variables********/
extern char *diff_so_file;
extern int  difftest_port;
extern long img_size;
extern NPCState npc_state;
extern void   init_monitor(int, char *[]);
extern void   sdb_mainloop() ;
extern int    is_exit_status_bad();
extern void   init_difftest(char *ref_so_file, long img_size, int port);
extern word_t pmem_r(paddr_t addr, int len); 
extern void   pmem_w(paddr_t addr, int len, word_t data);
extern void   ebreak(int station, int inst);                   // control_unit.v
extern int    pmem_read(int raddr, int num);                   // mem.v
extern void   pmem_write(int waddr, int wdata, char wmask);    // mem.v
extern void   etrace(int inst);                                     // control_unit.v
extern uint64_t get_time();                               
extern void difftest_skip_ref();
/*********************************************/

#define start_time 3

static uint32_t rtc_port_base[2] = {0, 0};

static const char *alu_names[17] = {
  "Unit_ALU", "Unit_MEM", "Unit_CU1", "Unit_CU2",
  "Unit_CU3", "Unit_CU4", "Unit_CU5", "Unit_CU6",
  "Unit_CU7", "Unit_CU8", "Unit_CU9", "Unit_CU10",
  "Unit_CU11","Unit_IE1", "Unit_IE2", "Unit_IE3",
  "Unit_CR"
};

extern void ebreak(int station, int inst, char unit)
{
  if(Verilated::gotFinish())
    return;
    // Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, top->rootp->ysyx_23060219_top__DOT__pc, top->rootp->ysyx_23060219_top__DOT__inst);

  //虽然波形图上inst随pc同时变化，但通过打印二者会发现inst会在pc变化之后才改变（这是因为二者都发生变化了之后才输出至波形图的）
  //然而，这个延时会导致decode错误，然后调用了 “ebreak(`ABORT, inst);”
  if(main_time >= start_time + 1)   // at the begining (main_time < start_time and before the reset), all regs are zeros
  {
    npc_state.halt_ret = top->rootp->ysyx_23060219_top__DOT__register_file_inst__DOT__regs[10]; //a0
    npc_state.halt_pc = top->rootp->ysyx_23060219_top__DOT__pc;

    assert( (unit == Unit_ALU) || (unit == Unit_CU1) || (unit == Unit_CU2) || (unit == Unit_CU3) || 
            (unit == Unit_CU4) || (unit == Unit_CU5) || (unit == Unit_CU6) || (unit == Unit_CU7) || 
            (unit == Unit_CU8) || (unit == Unit_CU9) || (unit == Unit_CU10)|| (unit == Unit_CU11)||
            (unit == Unit_MEM) || (unit == Unit_IE1) || (unit == Unit_IE2) || (unit == Unit_IE3) ||
            (unit == Unit_CR) );

    Log("Ebreak takes place in the %s", alu_names[unit]);
    Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, top->rootp->ysyx_23060219_top__DOT__pc, top->rootp->ysyx_23060219_top__DOT__inst);

    switch(station)
    {
      case HIT_TRAP:
        npc_state.state = NPC_END;
        break;

      case ABORT:
      default:
        npc_state.state = NPC_ABORT;
        break;
    }

    Verilated::gotFinish(true);
  }
}

#define top_mstatus   top->rootp->mstatus
#define top_mepc      top->rootp->mepc
#define top_mcause    top->rootp->mcause


extern void etrace(int inst)
{
  _Log(ANSI_FG_YELLOW "[etrace]  " ANSI_NONE ANSI_FG_YELLOW "mstatus : " ANSI_NONE "0x%08x, "
       ANSI_FG_YELLOW "mepc : "    ANSI_NONE " 0x%08x, " ANSI_FG_YELLOW "mcause : " ANSI_NONE " 0x%08x\n", 
      top_mstatus, top_mepc, top_mcause);
}



extern int pmem_read(int raddr, int num)
{
  static int data = 0xdead0009;
  if(top->clk == 0)
    return data;

  if(main_time >= start_time)
  {
    // device rtc 判断时钟
    if((raddr == CONFIG_RTC_MMIO) || (raddr == CONFIG_RTC_MMIO + 4))
    {
      if(raddr == CONFIG_RTC_MMIO + 4)
      {
        uint64_t us = get_time();
        rtc_port_base[0] = (uint32_t)us;
        rtc_port_base[1] = us >> 32;
      }
      data = rtc_port_base[(raddr - CONFIG_RTC_MMIO) / 4];
#ifdef CONFIG_DIFFTEST
      difftest_skip_ref();
#endif
    }
    else
      data = pmem_r(raddr, 4);
    return data; 
    // return pmem_r((raddr & ~0x3u), 4);
  } 
  else
    return 0xdead0009;
}


void pmem_write(int waddr, int wdata, char wmask)
{
  if(top->clk == 0)   // 写操作仅在时钟为高电平时有效
    return;

  // device serial  判断串口
  if(waddr == CONFIG_SERIAL_MMIO)
  {
    assert(wmask == WByte);   // 确保写掩码是字节
    char ch = (char)wdata;    // 将写入数据转换为字符
    putchar(ch);              // 将字符输出到串口

#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();     // 跳过参考模型的测试
#endif

    return;
  }

  // memory 不是串口地址则进行内存写入
  switch (wmask)    // 写掩码类型
  {
    case WByte: pmem_w(waddr, 1, wdata);  // 字节
                break;
    case WHalf: pmem_w(waddr, 2, wdata);  // 半字（两个字节）
                break;
    case WWord: pmem_w(waddr, 4, wdata);  // 字（四个字节）
                break;
    default:    assert(0);
                break;
  }
}


void single_cycle(void) 
{
  if(!Verilated::gotFinish())
  { 
    top->clk = 0; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);  
#endif
    main_time++; //推动仿真时间

    top->clk = 1; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);  
#endif
    main_time++; //推动仿真时间
  }
}

static void reset(void)
{
  top->rst = 0; single_cycle();
  top->rst = 1; single_cycle();
  top->rst = 0; 
}

static void init_verilator(void)
{
  Verilated::traceEverOn(true); //导出fst波形需要加此语句

  top->trace(tfp, 0);
  tfp->open("waveform.fst"); //打开fst

  reset();  //复位
}


// void close_tfp(void)
// {
//   tfp->close();
// }

int main(int argc, char *argv[])
{
  /* Initialize the monitor. */
  init_monitor(argc, argv);

  /* Initialize the verilator. */
  init_verilator();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Receive commands from user. */
  sdb_mainloop();

  /* End the simulation */
  top->final();
  tfp->close();
  delete top;

  return is_exit_status_bad();
}