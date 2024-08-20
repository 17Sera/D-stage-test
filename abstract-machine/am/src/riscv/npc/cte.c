#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {      // 三个参数都没有传进来 mcause mstatus mepc

  // printf("------------ c->mcause = %x ,  c->mstatus = %u  ,  c->mepc = %u --------------------in __am_irq_handle ---------------\n", c->mcause, c->mstatus , c->mepc);

  if (user_handler) {
    Event ev = {0};

    // printf("\n -------------------------  c->mcause = %p  ------------------------------\n", c->mcause);  //mcause不等于0xb 等于0x4

    switch (c->mcause) {
      case 0xb: ev.event = EVENT_YIELD; 
                c->mepc = c->mepc + 4;  // 执行下一次的指令，进入下一次循环，再经过一个空循环再yield，否则一直yield一直都是同一个指令
                break;
      default: ev.event = EVENT_ERROR; break;
    }

    // printf("\n -------------------------  ev.event = %p  ------------------------------\n", ev.event);
    // printf("\n -------------------------  EVENT_ERROR = %p  ------------------------------\n", EVENT_ERROR);
    // printf("\n----------- c->mcause = %p, c->mstatus = %p , c->mepc = %p------------- \n", c->mcause, c->mstatus , c->mepc);

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);



bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}



Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {

  Context *c = (Context*)kstack.end - 1;  // 这里的1等同于一个Context大小  // 上下文指针 c 指向栈的起始地址

  // printf("\n---------------- c = %p   ,  kstack.end = %p -------------------\n",c,kstack.end);

  //栈底在上，栈顶在下
  // Context *c = kstack.end - 4 - sizeof(Context);

  //c->mcause = 0xb;
  c->mstatus = 0x1800;                    // difftest pass
  c->mepc = (uintptr_t) entry;            // 创建以entry为入口的上下文

  // printf("\n----------- c->mcause = %p, c->mstatus = %p , c->mepc = %p------------- \n", c->mcause, c->mstatus , c->mepc);


  //入口函数为f()
  // for(int i = 0; i < NR_REGS; i++)
  //   c->gpr[i] = 0;
  
  //观察汇编，a0为传参寄存器
  c->gpr[10] = (uintptr_t)arg;  // gpr[10] 对应a0

  // printf("\n--------------- arg = %u  ,  a0 = %u -----------------\n",arg,c->gpr[10]);

  return c;
}




void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, 0xb; ecall"); //汇编指令用来触发一个系统调用（ECALL）
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
