#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <am.h>
#include <klib-macros.h>
#include "../riscv.h"
#include "ysyxsoc.h"

#define soc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code)) 

extern char _heap_start , _heap_end;
// extern char _data_start[] , _data_end[] , _m_data_start[];
// extern char _bss_start[] , _bss_end[];
extern char _data_start , _data_end , _m_data_start;
extern char _bss_start , _bss_end;


int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

// void putch(char ch) {
//   outb(SERIAL_PORT, ch);
// }


void putch(char ch) {
  // init_uart();
  while ((inb(UART_LSR) & UART_LSR_EMPTY_MASK) == 0);   // 查询串口发送队列的情况,等待fifo空闲
  outb(UART_THR, ch);
}


void halt(int code) {
  soc_trap(code);
  while (1);
}


void bootloader() {
  // 定义段的大小
  // size_t data_size = _data_end - _data_start;
  // size_t bss_size = _bss_end - _bss_start;
  // memcpy(_data_start, _m_data_start, data_size);   // 复制.data段
  // memset(_bss_start, 0, bss_size);                 // 清零.bss段

  char* p = &_m_data_start;
  for(char* i=&_data_start; i<&_data_end; i++, p++) {
    *i = *p;      // 复制.data段
  }
  for(char* i=&_bss_start; i<&_bss_end; i++) {
    *i = 0;       // 清零.bss段
  }
}

void init_uart(void)
{
  outb(UART_LCR, 0x80);   // 启用除数寄存器
  // outb(UART_LCR, 0b10000011);
  outb(UART_DLH, 0x00);   // 波特率分频器高字节
  outb(UART_DLL, 0x08);   // 波特率分频器低字节
  outb(UART_LCR, 0x03);   // DLAB位置为0，恢复正常寄存器访问
}


void _trm_init() {
  init_uart();
  bootloader();
  int ret = main(mainargs);
  halt(ret);
}
