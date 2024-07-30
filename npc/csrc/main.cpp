// //================== 定义读取bin文件指令版 ===================================
// #include <stdio.h> 
// #include <stdlib.h> 
// #include <assert.h>
// // #include <stdint.h>
// #include <time.h> 
// #include "Vriscv_top.h"  
// #include "verilated_vcd_c.h" 
// // #include "Vriscv_top__Dpi.h"
// // #include <verilated_dpi.h>

// // //-------------------------------------------------------------------------------
// Vriscv_top *top; 
// vluint64_t cur_time;

// double sc_time_stamp(){     //仿真时间戳函数
//     return cur_time;  }

// void time_inc(){
//     cur_time++;}


// //================== img =========================          //////////////////////////

// //请求分配size个uint32_t所需的内存空间并返回指向这块内存空间的指针 memory

// static long load_img();

// //static char *img_file = "/home/zhong/ysyx-workbench/npc/image.bin";

// uint32_t *memory = (uint32_t *) malloc ( 10 *sizeof(uint32_t) );    ////////分配size

// uint32_t guest_to_host ( uint32_t addr ) {
//     return addr - 0x80000000;
// }

// uint32_t pmem_read ( uint32_t *memory , uint32_t vaddr ){
//     uint32_t paddr = guest_to_host( vaddr );
//     return memory[paddr/4];         //paddr/4为序列号
// }

// //===================== main =======================
// int main(int argc, char **argv){
//  //   uint32_t *memory = init_mem(3);             /////////////////
   
//     Verilated::commandArgs(argc,argv); 
//     Verilated::traceEverOn(true);               //Verilator开启VCD波形记录功能
//     VerilatedVcdC *vcd = new VerilatedVcdC;     //用于管理Verilator的仿真上下文，包括仿真状态和配置参数
//     srand((unsigned)time(NULL)); 
//     top = new Vriscv_top("top"); 
//     top->trace(vcd,0);                          //关联top和vcd，使得vcd可以记录top模块的信号变化
//     vcd->open("wave.vcd");                      //打开名为 wave.vcd 的文件，准备开始记录仿真信号变化

// //--------------------- load the img to memory ------------------------------
//     long img_size = load_img();
// //-----------------------复位到开启cpu_init ---------------------
//     top -> clk = 0;
//     top -> reset = 1;
//     top -> eval(); 
//     vcd -> dump(sc_time_stamp()); 
//     time_inc();

//     top -> clk = 1;
//     top -> reset = 1;
//     top -> eval(); 
//     vcd -> dump(sc_time_stamp()); 
//     time_inc();
// //----------------------------------------------------
//     //sc_time_stamp() 返回当前仿真时间
//     while(sc_time_stamp()< 30 && !Verilated::gotFinish()){
//         top -> reset = 0;
//         top -> clk = 0;
//         top -> Instr = pmem_read( memory , top -> PC );     /////////////////////
//         top -> eval(); 
//         vcd -> dump(sc_time_stamp()); 
//         time_inc(); 

//         top -> clk = 1;
//         top -> eval(); 
//         vcd -> dump(sc_time_stamp()); 
//         time_inc(); 
//     }
//     free (memory);          /////////////////////

//     top->final(); 
//     vcd->close(); 
//     delete top; 
//     delete vcd; 
//     return 0;
// }

// static long load_img() {      //加载一个镜像文件到内存中,并返回镜像文件的大小
//     if (img_file == NULL) {     //检查是否有指定的镜像文件路径
//     //Log("No image is given. Use the default build-in image.");  //没有外部指定的镜像文件，使用内置的镜像文件
//     printf("No image is given. Use the default build-in image.\n");
//     return 4096;              //默认的内置镜像大小为4096字节
//     }
//     FILE *fp = fopen(img_file, "rb");
//     //Assert(fp, "Can not open '%s'", img_file);  //确保文件成功打开
//     if( fp == NULL ) {
//         printf("Can not open '%s'\n", img_file);
//         assert(0);
//     }
//     fseek(fp, 0, SEEK_END);   //文件指针移动到文件末尾
//     long size = ftell(fp);    //获取文件大小，字节数
//     //Log("The image is %s, size = %ld", img_file, size);
//     printf("The image is %s, size = %ld", img_file, size);
//     fseek(fp, 0, SEEK_SET);   //文件指针移动到文件开头，准备开始读取文件内容
//     //int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);    //fread从打开的文件中 读取size字节的数据，并将其写入guest_to_host(RESET_VECTOR)指向的内存地址中
//     int ret = fread(memory, size, 1, fp);
//     assert(ret == 1);         //检查 是否读取成功
//     fclose(fp);
//     return size;              //返回读取的镜像文件的大小
// }







//=======================定义数组存放指令版===================================
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>
#include <time.h> 
#include "Vriscv_top.h"  
#include "verilated_vcd_c.h" 
#include "Vriscv_top__Dpi.h"
#include <verilated_dpi.h>

#define MAX_SIM_TIME 30     //最大仿真时间
#define INIT_MEM_SIZE 10    //初始化内存大小，初始化=0

///# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))     ////////////////////
//--------------------------------------------------------------------------
Vriscv_top *top; 
vluint64_t cur_time;

double sc_time_stamp(){     //仿真时间戳函数
    return cur_time;  }

void time_inc(){
    cur_time++;}

//--------------------------- npc_trap ------------------------------------------
int flag = 0;
void npc_trap( int stop_signal ) {
    flag = stop_signal;
    printf("flag = %d\n",flag);     /////////
}
//---------------------------- ebreak ------------------------------------------

extern "C" void ebreak( int stop_signal ){
    printf("----------------------------------- ebreak ------------------------------------------- \n");
    npc_trap(stop_signal);
  // should not reach here
    return;
}
//---------------------------- img -----------------------------------------
// static const uint32_t img[] = {             //二进制指令
//     0b00000000010100000000000010010011,     //addi x1 x0 5
//     0b00000000000100000000000100010011,     //addi x2 x0 1
//     0b00000000001000000000000100010011,     //addi x2 x0 2
//     0b00000000010100001000000100010011      //addi x2 x15
// };

// static const uint32_t img[] = {             //十六进制非小端指令
//     0x500093    ,     //addi x1 x0 5
//     0x100113    ,     //addi x2 x0 1
//     0x200113    ,     //addi x2 x0 2
//     0x508113          //addi x2 x15
// };

static const uint32_t img[] = {             //十六进制小端序列指令
    // 0x390005    ,     //addi x1 x0 5
    // 0x311001    ,     //addi x2 x0 1
    // 0x311002          //addi x2 x0 2
       0x1c0c93    ,     //ADDI $25 $24 32'h00000001
       0x100073          //ebreak
};

//---------------------------- init_mem  -----------------------------------------

uint32_t *init_mem ( size_t size ) {
    uint32_t *memory = (uint32_t *) malloc ( size * sizeof(uint32_t) );    ////////分配size
    memset(memory, 0, size * sizeof(uint32_t));     //内存初始化为0

    memcpy( memory , img , sizeof(img) );
    if( memory==NULL ) {
        exit(0);
    }
    return memory;
}

uint32_t guest_to_host ( uint32_t addr ) {
    return addr - 0x80000000;
}

uint32_t pmem_read ( uint32_t *memory , uint32_t vaddr ){
    uint32_t paddr = guest_to_host( vaddr );
    return memory[paddr/4];         //paddr/4为序列号
}

//===================== main ======================================
int main(int argc, char **argv){
   
    Verilated::commandArgs(argc,argv); 
    Verilated::traceEverOn(true);               //Verilator开启VCD波形记录功能
    VerilatedVcdC *vcd = new VerilatedVcdC;     //用于管理Verilator的仿真上下文，包括仿真状态和配置参数
    srand((unsigned)time(NULL)); 
    top = new Vriscv_top("top"); 
    top->trace(vcd,0);                          //关联top和vcd，使得vcd可以记录top模块的信号变化
    vcd->open("wave.vcd");                      //打开名为 wave.vcd 的文件，准备开始记录仿真信号变化
//---------------------- init memory ---------------------------
    uint32_t *memory = init_mem( INIT_MEM_SIZE );            //size为10，也只将10个uint32_t初始化为0

//-----------------------复位到开启cpu_init ---------------------
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
//---------------------------------------------------------------
    //sc_time_stamp() 返回当前仿真时间
    while(sc_time_stamp()< MAX_SIM_TIME && !Verilated::gotFinish()){

        top -> reset = 0;
        top -> clk = 0;
        top -> Instr = pmem_read( memory , top -> PC );     /////////////////////
        top -> eval(); 
        vcd -> dump(sc_time_stamp()); 
        time_inc(); 

        top -> clk = 1;
        top -> eval(); 
        vcd -> dump(sc_time_stamp()); 
        time_inc(); 

        if( flag == 1 ){
            printf("Simulation finished \n");
            flag == 0;
            free (memory);          /////////////////////
            top->final();                       //////////////////////
            vcd->close(); 
            delete top; 
            delete vcd; 
            return 0;
        }
    }
    free (memory);          /////////////////////

    top->final(); 
    vcd->close(); 
    delete top; 
    delete vcd; 
    return 0;
}





