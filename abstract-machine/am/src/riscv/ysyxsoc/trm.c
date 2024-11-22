#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <am.h>
#include <klib-macros.h>
#include "../riscv.h"

#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))   ///////////

extern char _heap_start,_heap_end;

int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

// void putch(char ch)
// {
//   while ((inb(UART16550_LSR) & (0x1 << 5)) == 0x0)
//     ;
//   outb(UART16550_TX, ch);
// }

// void halt(int code) {
//   npc_trap(code);
//   // should not reach here
//   while (1);
// }

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
