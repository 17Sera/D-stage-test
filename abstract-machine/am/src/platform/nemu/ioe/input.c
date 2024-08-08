#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

// void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
//   kbd->keydown = 0;
//   kbd->keycode = AM_KEY_NONE;   // keycode 为按键的断码   没有按键时，keycode 为 AM_KEY_NONE
// }


void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  int key = AM_KEY_NONE;
  key = inl(KBD_ADDR);
  kbd->keydown = (key & KEYDOWN_MASK ? true : false);   // 确定按键是否按下
  kbd->keycode = key & ~KEYDOWN_MASK;     // 清除key中表示按键状态的位，从而提取出真正的按键码
}
