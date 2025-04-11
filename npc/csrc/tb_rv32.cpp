#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_vcd_c.h"
#include "svdpi.h"
#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull.h"

/*------------------------------------------------------------------------------------*/
VysyxSoCFull  *top = new VysyxSoCFull("top");
VerilatedVcdC *tfp = new VerilatedVcdC(); 

vluint64_t      main_time = 0;
/*------------------------------------------------------------------------------------*/
extern char     *diff_so_file;
extern int      difftest_port;
extern long     img_size;
extern NPCState npc_state;

extern void     sdb_mainloop      () ;
extern void     init_monitor      (int, char *[]);
extern int      is_exit_status_bad();
extern void     init_difftest     (char *ref_so_file, long img_size, int port);
extern word_t   pmem_r            (paddr_t addr, int len); 
extern void     pmem_w            (paddr_t addr, int len, word_t data);
extern void     TRAP              (int station, char unit);                                              
extern uint64_t get_time          ();                               
extern void     difftest_skip_ref ();
/*------------------------------------------------------------------------------------*/

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

/*------------------------------------------------------------------------------------------------*/

void single_cycle(void) 
{
  if(!Verilated::gotFinish())
  { 
    top->clock = 0; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);  
#endif
    main_time++; 

    top->clock = 1; top->eval(); 
#ifdef CONFIG_WAVES
    tfp->dump(main_time);  
#endif
    main_time++; 
  }
}
/*------------------------------------------------------------------------------------------------*/

static void reset(void)
{
  top->reset = 0; single_cycle();
  top->reset = 1; single_cycle();single_cycle();single_cycle();single_cycle();single_cycle();single_cycle();
  single_cycle(); single_cycle();single_cycle();single_cycle();single_cycle();single_cycle();single_cycle();
  top->reset = 0;
}

/*------------------------------------------------------------------------------------------------*/

static void init_verilator(void)
{
  Verilated::traceEverOn(true); 

  top->trace(tfp, 0);
  // tfp->open("waveform.fst");
  tfp->open("waveform.vcd"); 
  reset(); 
}

/*------------------------------------------------------------------------------------------------*/

void close_tfp(void)
{
  tfp->close();
}

/*------------------------------------------------------------------------------------------------*/

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






/* ------------------------------------  unused  ---------------------------------------------------------- */
// void pmem_write(int waddr, int wdata, char wmask){
//   // if(main_time < start_time || top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clock_cnt != 3)  //clk_cnt == 3 表示LSU处于内存访问阶段
//     if(main_time < start_time ){
//       return;
//     }

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