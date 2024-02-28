#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <time.h> 
#include "Vexample.h"  
#include "verilated_vcd_c.h" 

Vexample *top; 
vluint64_t cur_time;

double sc_time_stamp(){ 
    return cur_time;  }

void time_inc(){
    cur_time++;}

int main(int argc, char **argv){
    Verilated::commandArgs(argc,argv); 
    Verilated::traceEverOn(true); 
    VerilatedVcdC *vcd = new VerilatedVcdC; 
    srand((unsigned)time(NULL)); 
    top = new Vexample("top"); 
    top->trace(vcd,0); 
    vcd->open("wave.vcd"); 
    while(sc_time_stamp()<20 && !Verilated::gotFinish()){
        int a = rand() & 1; 
        int b = rand() & 1; 
        top -> a = a; 
        top -> b = b; 
        top -> eval(); 
        vcd -> dump(sc_time_stamp()); 
        time_inc(); }
        
    top->final(); 
    vcd->close(); 
    delete top; 
    delete vcd; 
    return 0;}

