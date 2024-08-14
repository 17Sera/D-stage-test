#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;


// __am_asm_trap调用__am_irq_handle 用于构造事件
Context* __am_irq_handle(Context *c) {
  if (user_handler) {     //user_handler是cte_init中注册的回调函数
    Event ev = {0};

    switch (c->mcause) {
      case 0xb: ev.event = EVENT_YIELD; 
                c->mepc = c->mepc + 4;  // 执行下一次的指令，进入下一次循环，再经过一个空循环再yield，否则一直yield一直都是同一个指令
                break;
      default: ev.event = EVENT_ERROR; break;
    }
    //printf("c->mcause = %d, c->mstatus = %d , c->mepc = %d\n", c->mcause, c->mstatus , c->mepc);

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}


extern void __am_asm_trap(void);



bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));    // 异常处理的入口地址设置为__am_asm_trap
                                                            // %0 表示内联汇编指令中第一个操作数，在这里是__am_asm_trap，“r”表示将一个寄存器作为输入操作数
  // register event handler
  user_handler = handler;     // 将用户提供的 事件处理程序函数指针handler 赋值给全局变量user_handler，将用于事件发生时 处理事件和返回上下文
                              //user_handler是cte_init中注册的回调函数
  return true;
}


//kstack是栈的范围, entry是内核线程的入口, arg则是内核线程的参数.

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {

  //Context *c = (Context *)(kstack.end - sizeof(Context));     // -4？ // 得到并指向栈中上下文结构体指针的起始地址
  Context *c = (Context*)kstack.end - 1;          // 这里的1等同于一个Context
  c->mcause = 0xb;
  c->mstatus = 0x1800;            // difftest pass
  c->mepc = (uintptr_t) entry;      // 当前进程的上下文指针保存在PCB当中

  // //入口为f()
  // c->mepc = (uint32_t)entry;
  // for(int i = 0; i < NR_REGS; i++)
  //   c->gpr[i] = 0;
  
  // //观察汇编，a0为传参寄存器
  // c->gpr[10] = (uint32_t)arg;


  return c;
}




void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");   //通过ecall指令来进行自陷 //ecall再调用isa_raise_intr() 
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
