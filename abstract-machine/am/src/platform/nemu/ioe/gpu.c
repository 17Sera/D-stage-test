#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {    // 实现成功后 可以去掉测试代码
  // int i;
  // uint32_t screen_wh = inl(VGACTL_ADDR);
  // uint32_t w = screen_wh >> 16;
  // uint32_t h = screen_wh & 0xffff;
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for( i = 0; i < w * h; i++ ) fb[i] = i;   // 遍历屏幕的每个像素位置，将每个像素的索引值赋给帧缓冲区对应位置的值，用于初始化显示内容
  // outl(SYNC_ADDR, 1);
}

// void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
//   *cfg = (AM_GPU_CONFIG_T) {
//     .present = true, .has_accel = false,
//     .width = 0, .height = 0,
//     .vmemsz = 0
//   };
// }

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t screen_wh = inl(VGACTL_ADDR);
  uint32_t h = screen_wh & 0xffff;
  uint32_t w = screen_wh >> 16;
  *cfg = (AM_GPU_CONFIG_T) {        // 用于描述和初始化图形处理单元（GPU）的配置信息
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = 0
  };
}



// void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
//   if (ctl->sync) {
//     outl(SYNC_ADDR, 1);
//   }
// }


void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;   // 从像素数据数组 pixels 中读取图像数据
  if (!ctl->sync && (w == 0 || h == 0)) return;
  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t screen_w = inl(VGACTL_ADDR) >> 16;
  for (int i = y; i < y+h; i++) {
    for (int j = x; j < x+w; j++) {
      fb[screen_w*i+j] = pixels[w*(i-y)+(j-x)];   // 根据屏幕宽度 screen_w 计算每个像素的存储位置
    }
  }
  if (ctl->sync) {    // 决定是否进行同步操作
    outl(SYNC_ADDR, 1);
  }
}


void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
