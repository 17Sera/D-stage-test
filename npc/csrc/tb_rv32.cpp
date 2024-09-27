//// 单周期和加完握手

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include "Vysyx_23060219.h"
// #include "verilated_fst_c.h"
// #include "Vysyx_23060219__Dpi.h"
// #include "svdpi.h"
// #include "../include/common.h"
// #include "../include/utils.h"
// #include "../include/debug.h"
// #include "Vysyx_23060219___024root.h"


// Vysyx_23060219 *top = new Vysyx_23060219("top");
// VerilatedFstC *tfp = new VerilatedFstC(); //导出fst波形需要加此语句
// vluint64_t    main_time = 0;  //initial 仿真时间



// /********extern functions or variables********/
// extern char     *diff_so_file;
// extern int      difftest_port;
// extern long     img_size;
// extern NPCState npc_state;

// extern void   sdb_mainloop() ;
// extern void   init_monitor(int, char *[]);
// extern int    is_exit_status_bad();
// extern void   init_difftest(char *ref_so_file, long img_size, int port);
// extern word_t pmem_r(paddr_t addr, int len); 
// extern void   pmem_w(paddr_t addr, int len, word_t data);
// extern void   TRAP(int station, char unit);             
// extern int    imem_read(int raddr);                 
// extern int    dmem_read(int raddr);                  
// extern void   pmem_write(int waddr, int wdata, char wmask);    
// // extern void   etrace(int inst);                                     
// extern uint64_t get_time();                               
// extern void   difftest_skip_ref();
// /*********************************************/

// static uint32_t rtc_port_base[2] = {0, 0};
// static const char *unit_names[14] = {
//   "Unit_IDU1", "Unit_IDU2", "Unit_IDU3", "Unit_IDU4",
//   "Unit_IDU5", "Unit_IDU6", "Unit_IDU7", "Unit_IDU8", 
//   "Unit_IDU9", "Unit_EXU1", "Unit_LSU1", "Unit_LSU2",
//   "Unit_CC1 ", "Unit_CC2"
// };

// #define start_time 3
// extern void TRAP(int station, char unit)
// {
//   if(Verilated::gotFinish())
//     return;

//   // at the begining (main_time < start_time and before the reset), all gprs are zeros
//   if(main_time >= start_time + 1)   
//   {
//     npc_state.halt_ret = top->rootp->ysyx_23060219__DOT__register_file_inst__DOT__regs[10]; //a0
//     npc_state.halt_pc = top->rootp->ysyx_23060219__DOT__bru_inst__DOT__npc_reg;

//     assert( (unit == Unit_IDU1) || (unit == Unit_IDU2) || (unit == Unit_IDU3) || (unit == Unit_IDU4) || 
//             (unit == Unit_IDU5) || (unit == Unit_IDU6) || (unit == Unit_IDU7) || (unit == Unit_IDU8) ||
//             (unit == Unit_IDU9) || (unit == Unit_EXU1) || (unit == Unit_LSU1) || (unit == Unit_LSU2) ||
//             (unit == Unit_CC1)  || (unit == Unit_CC2));

//     Log("TRAP takes place in the %s", unit_names[unit]);
//     Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, 
//          top->rootp->ysyx_23060219__DOT__bru_inst__DOT__npc_reg, top->rootp->ysyx_23060219__DOT__ifu_inst__DOT__ifu_inst);

//     switch(station)
//     {
//       case HIT_TRAP:
//         npc_state.state = NPC_END;
//         break;

//       case ABORT:
//       default:
//         npc_state.state = NPC_ABORT;
//         break;
//     }

//     Verilated::gotFinish(true);
//   }
// }


// extern int imem_read(int raddr)
// {
//   static int data = 0xdead0009;

//   if(main_time < start_time)  //表示内存还未初始化或尚未开始工作
//     return data;
  
//   data = pmem_r(raddr, 4);  // 从物理内存中读取数据,通常用于读取一条程序指令---读取的长度为4个字节,32位
//   return data;    
// }


// extern int dmem_read(int raddr)
// {
//   static int data = 0xdead000a;

//   // 因为是周期CPU，所以理论上来说应该轮到LSU工作的时候才读/写dmem
//   // if(main_time < start_time || top->rootp->ysyx_23060219__DOT__clock_cnt != 3)
//   if(main_time < start_time )
//     return data;

//   // device rtc 检查读取地址是否为 RTC 的内存映射IO地址
//   if((raddr == CONFIG_RTC_MMIO) || (raddr == CONFIG_RTC_MMIO + 4)){
//     if(raddr == CONFIG_RTC_MMIO + 4){   //如果是高32位地址
//       uint64_t us = get_time();         //获取当前时间
//       rtc_port_base[0] = (uint32_t)us;  //拆分为低32位和高32位分别存入 rtc_port_base 中
//       rtc_port_base[1] = us >> 32;
//     }
//     data = rtc_port_base[(raddr - CONFIG_RTC_MMIO) / 4];
// #ifdef CONFIG_DIFFTEST
//     difftest_skip_ref();
// #endif
//   }
//   else
//     data = pmem_r(raddr, 4);  //如果不是RTC地址，则从物理内存中读取数据（通过pmem_r）
//   return data;   
// }


// void pmem_write(int waddr, int wdata, char wmask){
//   // 因为是周期CPU，所以理论上来说应该轮到LSU工作的时候才读/写dmem
//   if(main_time < start_time || top->rootp->ysyx_23060219__DOT__clock_cnt != 3)  //clk_cnt == 3 表示LSU处于内存访问阶段
//     // if(main_time < start_time )
//     return;

//   // device serial
//   if(waddr == CONFIG_SERIAL_MMIO){
//     assert(wmask == WByte);
//     char ch = (char)wdata;
//     putchar(ch);
// #ifdef CONFIG_DIFFTEST
//     difftest_skip_ref();
// #endif
//     return;
//   }

//   // memory
//   switch (wmask){
//     case WByte: pmem_w(waddr, 1, wdata);
//                 break;
//     case WHalf: pmem_w(waddr, 2, wdata);
//                 break;
//     case WWord: pmem_w(waddr, 4, wdata);
//                 break;
//     default:    assert(0);
//                 break;
//   }
// }


// void single_cycle(void) 
// {
//   if(!Verilated::gotFinish())
//   { 
//     top->clk = 0; top->eval(); 
// #ifdef CONFIG_WAVES
//     tfp->dump(main_time);  
// #endif
//     main_time++; //推动仿真时间

//     top->clk = 1; top->eval(); 
// #ifdef CONFIG_WAVES
//     tfp->dump(main_time);  
// #endif
//     main_time++; //推动仿真时间
//   }
// }

// static void reset(void)
// {
//   top->rst = 0; single_cycle();
//   top->rst = 1; single_cycle();
//   top->rst = 0; single_cycle();
// }

// static void init_verilator(void)
// {
//   Verilated::traceEverOn(true); //导出fst波形需要加此语句

//   top->trace(tfp, 0);
//   tfp->open("waveform.fst"); //打开fst

//   reset();  //复位
// }

// void close_tfp(void)
// {
//   tfp->close();
// }

// int main(int argc, char *argv[])
// {
//   /* Initialize the monitor. */
//   init_monitor(argc, argv);

//   /* Initialize the verilator. */
//   init_verilator();

//   /* Initialize differential testing. */
// #ifdef CONFIG_DIFFTEST
//   init_difftest(diff_so_file, img_size, difftest_port);
// #endif
//   /* Receive commands from user. */
//   sdb_mainloop();

//   /* End the simulation */
//   top->final();
//   tfp->close();
//   delete top;

//   return is_exit_status_bad();
// }

// add sram ====================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_fst_c.h"
#include "svdpi.h"
#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull.h"

VysyxSoCFull *top = new VysyxSoCFull("top");
VerilatedFstC *tfp = new VerilatedFstC(); //导出fst波形需要加此语句
vluint64_t    main_time = 0;  //initial 仿真时间



/********extern functions or variables********/
extern char     *diff_so_file;
extern int      difftest_port;
extern long     img_size;
extern NPCState npc_state;

extern void   sdb_mainloop() ;
extern void   init_monitor(int, char *[]);
extern int    is_exit_status_bad();
extern void   init_difftest(char *ref_so_file, long img_size, int port);
extern word_t pmem_r(paddr_t addr, int len); 
extern void   pmem_w(paddr_t addr, int len, word_t data);
extern void   TRAP(int station, char unit);             
extern int    imem_read(int raddr);                 
extern int    dmem_read(int raddr);                  
extern void   pmem_write(int waddr, int wdata, char wmask);    
// extern void   etrace(int inst);                                     
extern uint64_t get_time();                               
extern void   difftest_skip_ref();

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) { assert(0); }
/*********************************************/

static uint32_t rtc_port_base[2] = {0, 0};
static const char *unit_names[14] = {
  "Unit_IDU1", "Unit_IDU2", "Unit_IDU3", "Unit_IDU4",
  "Unit_IDU5", "Unit_IDU6", "Unit_IDU7", "Unit_IDU8", 
  "Unit_IDU9", "Unit_EXU1", "Unit_LSU1", "Unit_LSU2",
  "Unit_CC1 ", "Unit_CC2"
};

#define start_time 3
extern void TRAP(int station, char unit)
{
  if(Verilated::gotFinish())
    return;

  // at the begining (main_time < start_time and before the reset), all gprs are zeros
  if(main_time >= start_time + 1)   
  {
    npc_state.halt_ret = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__register_file_inst__DOT__regs[10]; //a0
    npc_state.halt_pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bru_inst__DOT__npc_reg;

    assert( (unit == Unit_IDU1) || (unit == Unit_IDU2) || (unit == Unit_IDU3) || (unit == Unit_IDU4) || 
            (unit == Unit_IDU5) || (unit == Unit_IDU6) || (unit == Unit_IDU7) || (unit == Unit_IDU8) ||
            (unit == Unit_IDU9) || (unit == Unit_EXU1) || (unit == Unit_LSU1) || (unit == Unit_LSU2) ||
            (unit == Unit_CC1)  || (unit == Unit_CC2));

    Log("TRAP takes place in the %s", unit_names[unit]);
    // Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, 
    //      top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bru_inst__DOT__npc_reg, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__i_rdata);
    Log("maintime = %ld, state = %d, pc = 0x%08x, inst = 0x%08x", main_time, npc_state.state, 
         top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__bru_inst__DOT__npc_reg, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__w_ifu_inst);


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


extern int imem_read(int raddr)
{
  static int data = 0xdead0009;

  if(main_time < start_time)  //表示内存还未初始化或尚未开始工作
    return data;
  
  data = pmem_r(raddr, 4);  // 从物理内存中读取数据,通常用于读取一条程序指令---读取的长度为4个字节,32位
  return data;    
}


extern int dmem_read(int raddr)
{
  static int data = 0xdead000a;

  // if(main_time < start_time || top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clock_cnt != 3)
  if(main_time < start_time ){
    return data;
  }

  // device rtc 检查读取地址是否为 RTC 的内存映射IO地址
  if((raddr == CONFIG_RTC_MMIO) || (raddr == CONFIG_RTC_MMIO + 4)){
    if(raddr == CONFIG_RTC_MMIO + 4){   //如果是高32位地址
      uint64_t us = get_time();         //获取当前时间
      rtc_port_base[0] = (uint32_t)us;  //拆分为低32位和高32位分别存入 rtc_port_base 中
      rtc_port_base[1] = us >> 32;
    }
    data = rtc_port_base[(raddr - CONFIG_RTC_MMIO) / 4];
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
  }
  else
    data = pmem_r(raddr, 4);  //如果不是RTC地址，则从物理内存中读取数据（通过pmem_r）
  return data;   
}


void pmem_write(int waddr, int wdata, char wmask){
  // if(main_time < start_time || top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clock_cnt != 3)  //clk_cnt == 3 表示LSU处于内存访问阶段
    if(main_time < start_time ){
      return;
    }

  // device serial
  if(waddr == CONFIG_SERIAL_MMIO){
    assert(wmask == WByte);
    char ch = (char)wdata;
    putchar(ch);
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  // memory
  switch (wmask){
    case WByte: pmem_w(waddr, 1, wdata);
                break;
    case WHalf: pmem_w(waddr, 2, wdata);
                break;
    case WWord: pmem_w(waddr, 4, wdata);
                break;
    default:    assert(0);
                break;
  }
}


void single_cycle(void) 
{
  if(!Verilated::gotFinish())
  { 
    top->clock = 0; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);  
#endif
    main_time++; //推动仿真时间

    top->clock = 1; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);  
#endif
    main_time++; //推动仿真时间
  }
}

static void reset(void)
{
  top->reset = 0; single_cycle();
  top->reset = 1; single_cycle();
  top->reset = 0; single_cycle();
}

static void init_verilator(void)
{
  Verilated::traceEverOn(true); //导出fst波形需要加此语句

  top->trace(tfp, 0);
  tfp->open("waveform.fst"); //打开fst

  reset();  //复位
}

void close_tfp(void)
{
  tfp->close();
}

int main(int argc, char *argv[])
{
  /* Initialize the monitor. */
  init_monitor(argc, argv);

  /* Initialize the verilator. */
  Verilated::commandArgs(argc, argv);
  init_verilator();

  /* Initialize differential testing. */
#ifdef CONFIG_DIFFTEST
  init_difftest(diff_so_file, img_size, difftest_port);
#endif
  /* Receive commands from user. */
  sdb_mainloop();

  /* End the simulation */
  top->final();
  tfp->close();
  delete top;

  return is_exit_status_bad();
}

