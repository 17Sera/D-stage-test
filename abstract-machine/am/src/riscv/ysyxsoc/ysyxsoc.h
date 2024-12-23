#ifndef YSYXSOC_H__
#define YSYXSOC_H__

// #define MMIO_BASE            0xE0000000
// #define SERIAL_PORT          0x10000000
// #define CLINT_PORT           0x02000000
// #define KBD_ADDR             0x10011000
// #define VGACTL_ADDR          0x211FFFF0
// #define SYNC_ADDR            (VGACTL_ADDR + 4)
// #define FB_ADDR              0x21000000
// #define RTC_ADDR             (DEVICE_BASE + 0x0000048)
// #define AUDIO_ADDR           (DEVICE_BASE + 0x0000200)
// #define DISK_ADDR            (DEVICE_BASE + 0x0000300)
// #define AUDIO_SBUF_ADDR      (MMIO_BASE   + 0x1200000)




/* 串口发送数据： 1、检查发送FIFO状态 （读取 UART_LSR 寄存器的第五位（THRE 位），判断发送FIFO是否空闲） 
                 2、写入数据到 FIFO （将要发送的数据写入 UART_THR）
                 3、UART自动发送    （UART硬件自动将FIFO中的数据依次取出并通过串口发送）                       */

/* 串口接收数据： 1、检查发送FIFO状态 （读取 UART_LSR 寄存器的第0位（DR 位），判断接收FIFO是否有数据可读） 
                 2、读取数据        （从 UART_RXFIFO 中读取数据）
                 3、UART自动发送    （UART硬件自动将FIFO中的数据依次取出并通过串口发送）                       */

#define UART_BASE           0x10000000               // UART16550
#define UART_TXFIFO         ( UART_BASE + 0x00 )     // 发送数据
#define UART_RXFIFO         ( UART_BASE + 0x04 )     // 接收FIFO，存储接收到的数据，通过读取该寄存器，获取UART接收到的数据
#define UART_DLL            ( UART_BASE + 0x00 )     // 波特率分频器低字节
#define UART_DLH            ( UART_BASE + 0x01 )     // 波特率分频器高字节
#define UART_LCR            ( UART_BASE + 0x03 )     // 线路控制寄存器（除数寄存器）（配置 UART 数据格式，包括数据位、停止位、奇偶校验等。），第七位为DLAB：启用分频器访问模式，当设置为1时，可访问 DLL 和 DLH
#define UART_LSR            ( UART_BASE + 0x05 )     // 线路状态寄存器, 第五位为THRE（发送缓冲区空闲位）
#define UART_THR            ( UART_BASE + 0x00 )     // 向发送 FIFO 写入要发送的数据
#define UART_LSR_EMPTY_MASK ( UART_BASE + 0x20 )     // 发送缓冲区空闲位掩码，1=空闲，0=繁忙



#endif