#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 0xb: ev.event = EVENT_YIELD; 
                c->mepc = c->mepc + 4;  // 执行下一次的指令，进入下一次循环，再经过一个空循环再yield，否则一直yield一直都是同一个指令
                break;
      default : ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

// the function '__am_asm_trap' is the exception entry
extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  //栈底在上，栈顶在下
  Context *c = kstack.end - 4 - sizeof(Context);
  
  c->mcause = 0xb;            // 这里没有手动赋值，在硬件就需要手动赋值了，不能依靠读入，唯一的区别，但在其他也能跑，还有一点区别就是uintptr_t和uint32_t的区别
  c->mstatus = 0x1800;        // difftest pass
  //入口为f()
  c->mepc = (uint32_t)entry;  // 创建以entry为入口的上下文
  for(int i = 0; i < NR_REGS; i++)
    c->gpr[i] = 0;
  
  //观察汇编，a0为传参寄存器
  c->gpr[10] = (uint32_t)arg;
  return c;
}

void yield() {
#ifdef __riscv_e
  // asm volatile("li a5, -1; ecall");
  asm volatile("li a5, 0xb; ecall");
#else
  // asm volatile("li a7, -1; ecall");
  asm volatile("li a7, 0xb; ecall");  //汇编指令用来触发一个系统调用（ECALL）
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}