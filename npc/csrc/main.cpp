#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <time.h> 
#include "Vriscv_top.h"  
#include "verilated_vcd_c.h" 


// #include "verilated.h"
// //dpi-c
// // #include "Vtop__Dpi.h"
// #include <verilated_dpi.h>

// // Difftest
// #include <dlfcn.h>
// //readline
// #include <readline/readline.h>
// #include <readline/history.h>
// //system time
// #include <sys/time.h>



// //-------------------------------------------------------------------------------
Vriscv_top *top; 
vluint64_t cur_time;

double sc_time_stamp(){     //仿真时间戳函数
    return cur_time;  }

void time_inc(){
    cur_time++;}

int main(int argc, char **argv){
    Verilated::commandArgs(argc,argv); 
    Verilated::traceEverOn(true);               //Verilator开启VCD波形记录功能
    VerilatedVcdC *vcd = new VerilatedVcdC;     //用于管理Verilator的仿真上下文，包括仿真状态和配置参数
    srand((unsigned)time(NULL)); 
    top = new Vriscv_top("top"); 
    top->trace(vcd,0);                          //关联top和vcd，使得vcd可以记录top模块的信号变化
    vcd->open("wave.vcd");                      //打开名为 wave.vcd 的文件，准备开始记录仿真信号变化
    
//-----------------------复位到开启---------------------
    top -> clk = 0;
    top -> reset = 1;
    top -> eval(); 
    vcd -> dump(sc_time_stamp()); 
    time_inc();

    top -> clk = 1;
    top -> reset = 1;
    top -> eval(); 
    vcd -> dump(sc_time_stamp()); 
    time_inc();
//----------------------------------------------------
    //sc_time_stamp() 返回当前仿真时间
    while(sc_time_stamp()< 50 && !Verilated::gotFinish()){
        // int a = rand() & 1; 
        // int b = rand() & 1; 
        // top -> a = a; 
        // top -> b = b; 
        top -> reset = 0;
        top -> clk = 0;
        top -> eval(); 
        vcd -> dump(sc_time_stamp()); 
        time_inc(); 

        top -> clk = 1;
        top -> eval(); 
        vcd -> dump(sc_time_stamp()); 

        time_inc(); 
    }
        
    top->final(); 
    vcd->close(); 
    delete top; 
    delete vcd; 
    return 0;}





















// //-------------------------------------------------------------------------------

// //================= Environment ===============
// VerilatedContext* contextp;
// Vriscv_top *top; 
 
// VerilatedVcdC* tfp;
// vluint64_t main_time = 0;  //initial 仿真时间
// double sc_time_stamp()
// {
// 	return main_time;
// }
 
// uint64_t ref_regs[33];
 
// void hit_exit(int status) {}

// //================= Memory ====================
// addr_t img_size = 0;
// uint8_t pmem[10485760] = {0};
 
// uint8_t* cpu2mem(addr_t addr) {}
 
// void pmem_init() {
//   char image_path[] = "/home/zhong/ysyx-workbench/npc/image.bin";
// }

// //================= Exec =====================
// void cpu_init() {
//   //cpu_gpr[32] = CONFIG_MBASE;
//   top -> clk = 0;
//   top -> rst_n = 0;
//   top -> eval();
//   tfp->dump(main_time);
//   main_time ++;
//   top -> clk = 1;
//   top -> rst_n = 0;
//   top -> eval();
//   tfp->dump(main_time);
//   main_time ++;
//   top -> rst_n = 1;
// }


// void exec_once(VerilatedVcdC* tfp) {
//   top->clk = 0;
//   //printf("======clk shoule be 0 now %d\n",top->clk);
//   // top->mem_inst = pmem_read(top->mem_addr);
//   // printf("excute addr:0x%08lx inst:0x%08x\n",top->mem_addr,top->mem_inst);
//   top->eval();
//   tfp->dump(main_time);
//   main_time ++;
//   top->clk = 1;
//   //printf("======clk should be 1 now %d\n",top->clk); 
//   top->eval(); 
// 	tfp->dump(main_time);
//   main_time ++;
// }
 
// void cpu_exec(uint64_t n) {
//   for(int i; i < n; i++){
//       exec_once(tfp);
//       #ifdef CONFIG_DIFFTEST
//         difftest_exec_once();
//       #endif
//   }
// }



// //============ Main ============
// int main(int argc, char** argv, char** env) {
//   contextp = new VerilatedContext;
//   contextp->commandArgs(argc, argv);
//   top = new Vtop{contextp};
//   //VCD波形设置  start
//   Verilated::traceEverOn(true);
//   tfp = new VerilatedVcdC;
//   top->trace(tfp, 0);
//   tfp->open("wave.vcd");
//   //VCD波形设置  end
//   //initial data
//   pmem_init();
//   cpu_init();
 
//   #ifdef CONFIG_DIFFTEST
//     init_difftest();
//   #endif
 
// //   sdb_mainloop();
 
//   return 0;
// }

