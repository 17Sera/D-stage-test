#ifndef __TRACE_H__      
#define __TRACE_H__

#include <common.h>
#include <elf.h>
#include <device/map.h>

void parse_elf(const char *elf_file);

void display_call_func(word_t pc, word_t func_addr);

void display_ret_func(word_t pc);



#endif