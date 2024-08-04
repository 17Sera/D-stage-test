#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "common.h"
#include "utils.h"
#include <assert.h>

/*----------------- watchpoint -----------------*/
// void wp_display();
// void wp_set( char *expr, word_t res);
// void wp_delete ( int no );
// void wp_difftest();
/*----------------------------------------------*/

#define log_write(...)  \
  do { \
    extern FILE* log_fp; \
    fprintf(log_fp, __VA_ARGS__); \
    fflush(log_fp); \
  } while (0) \


#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)


#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)


#define Warn(format, ...) \
    printf(ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__)

#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      printf(ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__), \
      assert(cond); \
    } \
  } while (0)


#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

#endif