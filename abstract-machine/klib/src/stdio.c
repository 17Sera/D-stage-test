#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char NUM_CHAR[] = "0123456789ABCDEF";

//将整数转换为指定进制的字符串形式，存储到指定的字符数组中
//转换后的字符串将存储在str指针所指向的内存空间 //num为要转换的数字 //base为要转换的进制
// static char *number(char *str, int num, int base)  //返回指向转换后数字的下一个字符的指针
// {
//   assert( str && base );
//   int tmp[100], i = 0;
//   if(num < 0){        //处理负数，先在str指向处存负号
//     *str++ = '-';
//     num = -num;       //负数数值用绝对值（正数）处理
//   }
//   while( num ){         //不断取余、除法得到各个位上的数字，存在数组tmp
//     tmp[i++] = num % base;
//     num /= base;
//   }
//   i--;    //指针回退到转换后数字的最后一位


//   while(i >= 0) {       //转为字符型数字
//     *str++ = tmp[i--] + '0';  //将整数值(大于0的值)加上字符 '0' 的ASCII码值48---将整数转换为对应的字符
//     }   
//   return str;
// }
  
//out为输出字符串的缓冲区，fmt表示格式化字符串，ap表示可变参数列表
// int vsprintf(char *out, const char *fmt, va_list ap) {    
//   assert(out);
//   char *str = out; 
//   const char *s;
//   int base;   //进制
//   int num;    //被格式化的数字

//   for(; *fmt != '\0'; ++fmt){  
//     if(*fmt != '%'){
//       *str++ = *fmt;    //开头不是%---将该字符直接拷贝到输出字符串中
//       continue;         //继续下一个字符的处理
//     }

//     ++fmt;              //当前字符为%，让指针指向%下一个字符

//     base = 10;          //默认为10进制  

//     switch(*fmt){       //据%后一个字符分情况
//       case 'c':
//         *str++ = (unsigned char) va_arg(ap, int);
//         //从可变参数列表取出一个int型参数，转成unsigned char存入输出字符串中
//         continue;
//       case 's':
//         s = va_arg(ap, char *);   //从可变参数列表取出一个char *型参数

//         //for(int i = 0; s[i]; i++)
//         //  *str++ = s[i];
//         strcat(str, s);     //将该字符串拼接到输出字符串的末尾
//         str += strlen(s);   //更新输出字符串的位置指针
//         continue;

//       case 'd':
//         break;
        
//       default:
//         *str++ = '%';
//         if(*fmt)
//           *str++ = *fmt;
//         else
//           --fmt;    //防止溢出
//         continue;
//     }
//     num = va_arg(ap, int);

//     str = number(str, num, base); 
//     // %d 调用number来进行格式化处理，更新输出字符串的位置指针
//   }
//   *str = '\0';       //循环结束，输出字符串末尾加\0
//   return str - out;  //返回写入的字符数
// }
  

int vsprintf(char *out, const char *fmt, va_list ap) {
  	//panic("Not implemented");
	int	len = 0;
	char buf[128];
	while(*fmt != '\0') {
		switch(*fmt) {
			case '%':
				fmt++;
				switch(*fmt) {
					case 'd':
						int num_len;
						int val = va_arg(ap, int);
						if(val == 0)
							out[len++] = '0';
						if(val < 0) {
							out[len++] = '-';
							val = 0 - val;
						}
						for(num_len = 0; val; val /= 10, num_len++)
							buf[num_len] = NUM_CHAR[val % 10];
						for(int j = num_len - 1; j >=0; j--)
							out[len++] = buf[j];
						//out[len++] = '\0';
						break;
					case 'u':
						int unum32_len = 0;
						uint32_t unum32 = va_arg(ap, uint32_t);
						if(unum32 == 0) 
							out[len++] = '0';
						else {
							while(unum32 > 0) {
								buf[unum32_len++] = '0' + (unum32 % 10);
								unum32 /= 10;
							}
						}
						for(int i = unum32_len - 1; i >= 0; i--)
							out[len++] = buf[i];
						break;
					case 'c':
						char c = (char)va_arg(ap, int);
						out[len++] = c;
						break;
					case 's':
						char* s = va_arg(ap, char*);
						for(int i = 0; s[i] != '\0'; i++) 
							out[len++] = s[i];
						break;
					case 'x':
						unsigned int unum = va_arg(ap, unsigned int);
						if(unum == 0) {
							out[len++] = '0';
							break;
						}
						for(num_len = 0; unum; unum >>= 4, num_len++)
							buf[num_len] = NUM_CHAR[unum & 0xf];
						for(int i = num_len - 1; i >= 0; i--)
							out[len++] = buf[i];
						break;
					case 'p':
						out[len++] = '0'; out[len++] = 'x';
						uint32_t address = va_arg(ap, uint32_t);
						for(num_len = 0; address; address /= 16, num_len++)
							buf[num_len] = NUM_CHAR[address % 16];
						for(int i = num_len - 1; i >= 0; i--)
							out[len++] = buf[i];
						break;
				}
				break;
			case '\n':
				out[len++] = '\n';
				break;
			case '\r':
				out[len++] =  '\r';
				break;
			case '\t':
				out[len++] = '\t';
				break;
			default:
				out[len++] = *fmt;
		}
		fmt++;
	}
	out[len] = '\0';
	return len;
}




  
//out为输出字符串的缓冲区，fmt表示格式化字符串，...表示可变参数列表
int sprintf(char *out, const char *fmt, ...) {
  assert(out);

  va_list args;
  int i;

  va_start(args, fmt);   //va_start宏初始化可变参数列表，将fmt和args传入
  i = vsprintf(out, fmt, args); //vsprintf函数执行格式化字符串写入操作，返回写入的字符数
  va_end(args);   //va_end宏结束可变参数列表的处理，以释放相关资源

  return i;   //返回写入到输出字符串中的字符数
}


int printf(const char *fmt, ...) {
  //panic("Not implemented");
  int i;
  char buf[256];

  memset(buf, 0, sizeof(buf));

  va_list args;
  va_start(args, fmt);
  i = vsprintf(buf, fmt, args);
  va_end(args);

  char *tmp = buf;
  while(*tmp != 0){
    putch(*tmp);
    tmp++;
  }

  return i;
}


// static char sprint_buf[1024];
// /*可变函数在内部实现的过程中是从右向左压入堆栈，从而保证了可变参数的第一个参数始终位于栈顶*/
// int printf(const char *fmt, ...)//可以有一个或多个固定参数
// {
//   va_list args; //用于存放参数列表的数据结构
//   int n;
//   /*根据最后一个fmt来初始化参数列表，至于为什么是最后一个参数，是与va_start有关。*/
//   va_start(args, fmt);
//   n = vsprintf(sprint_buf, fmt, args);
//   va_end(args);//执行清理参数列表的工作
//   putstr(sprint_buf);
//   return n;
// }


int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif