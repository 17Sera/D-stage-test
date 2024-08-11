#include <am.h>
#include <klib.h>
#include <klib-macros.h>

//-----------------------------------------------------------
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
static char* start_addr;    // addr初始值
static bool init_flag = 0;  // 初始化的标志, 初始化完成后置1
// static char *hbrk;
//-----------------------------------------------------------

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

//---------------------------- the following nemu run wrong -----------------------------------------
// void malloc_reset() 
// {
//   hbrk = (void *)ROUNDUP(heap.start, 4);
// }

// void *malloc(size_t size) {
//   // On native, malloc() will be called during initializaion of C runtime.
//   // Therefore do not call panic() here, else it will yield a dead recursion:
//   //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
// #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
//   size = (size_t)ROUNDUP(size, 4);
//   char *old = hbrk;
//   hbrk += size;
//   assert((uintptr_t)heap.start <= (uintptr_t)hbrk && (uintptr_t)hbrk < (uintptr_t)heap.end);
//   for (uint32_t *p = (uint32_t *)old; p != (uint32_t *)hbrk; p ++) 
//   {
//     *p = 0;
//   }
//   return old;
//   panic("Not implemented");
// #endif
//   return NULL;
// }

//-----------------------------------------------------------------------------
void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  //panic("Not implemented");
    if(!init_flag) {
        start_addr = (void*)ROUNDUP(heap.start, 8);
        init_flag = true;
    }
    size = (size_t)ROUNDUP(size, 8);
    char* old = start_addr;
    start_addr += size;
    return old;
#endif
  return NULL;
}
//----------------------------------------------------------------------
// void *malloc(size_t size) {
//     if(!init_flag) {
//         start_addr = (void*)ROUNDUP(heap.start, 8);
//         init_flag = true;
//     }
//     size = (size_t)ROUNDUP(size, 8);
//     char* old = start_addr;
//     start_addr += size;
//     return old;
// }
//----------------------------------------------------------------------


void free(void *ptr) {
}

#endif
