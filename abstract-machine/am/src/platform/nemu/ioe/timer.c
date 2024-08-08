#include <am.h>
#include <nemu.h>

void __am_timer_init() {
  outl(RTC_ADDR, 0);
  outl(RTC_ADDR + 4, 0);
}

// void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {   // AM系统启动时间, 可读出系统启动后的微秒数
//   uptime->us = 0;
// }

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = inl(RTC_ADDR + 4);       // RTC_ADDR  (DEVICE_BASE + 0x0000048)
  uptime->us <<= 32;
  uptime->us += inl(RTC_ADDR);
}


void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {    // AM实时时钟,可读出当前的年月日时分秒. PA中暂不使用.
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}



 
