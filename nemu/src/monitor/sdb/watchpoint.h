#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"

typedef struct watchpoint
{
  int NO;
  struct watchpoint *next;
  char expr[32];
  uint32_t new_val;
  uint32_t old_val;
  uint8_t type;
  //0 is watchpoint, 1 is breakpoint.
} WP;

WP *new_wp();
void free_wp(WP *wp);
int set_watchpoint(char *e);
bool delete_watchpoint(int NO);
void list_watchpoint(void);
WP *scan_watchpoint(void);
int set_breakpoint(char *e);
void recover_int3();

#endif