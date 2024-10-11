// #include <am.h>
// #include <klib.h>
// #include <klib-macros.h>
// #include <stdarg.h>

// #if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// static char NUM_CHAR[] = "0123456789ABCDEF";


// int vsprintf(char *out, const char *fmt, va_list ap) {
//   	//panic("Not implemented");
// 	int	len = 0;
// 	char buf[128];
// 	while(*fmt != '\0') {
// 		switch(*fmt) {
// 			case '%':
// 				fmt++;
// 				switch(*fmt) {
// 					case 'd':
// 						int num_len;
// 						int val = va_arg(ap, int);
// 						if(val == 0)
// 							out[len++] = '0';
// 						if(val < 0) {
// 							out[len++] = '-';
// 							val = 0 - val;
// 						}
// 						for(num_len = 0; val; val /= 10, num_len++)
// 							buf[num_len] = NUM_CHAR[val % 10];
// 						for(int j = num_len - 1; j >=0; j--)
// 							out[len++] = buf[j];
// 						//out[len++] = '\0';
// 						break;
// 					case 'u':
// 						int unum32_len = 0;
// 						uint32_t unum32 = va_arg(ap, uint32_t);
// 						if(unum32 == 0) 
// 							out[len++] = '0';
// 						else {
// 							while(unum32 > 0) {
// 								buf[unum32_len++] = '0' + (unum32 % 10);
// 								unum32 /= 10;
// 							}
// 						}
// 						for(int i = unum32_len - 1; i >= 0; i--)
// 							out[len++] = buf[i];
// 						break;
// 					case 'c':
// 						char c = (char)va_arg(ap, int);
// 						out[len++] = c;
// 						break;
// 					case 's':
// 						char* s = va_arg(ap, char*);
// 						for(int i = 0; s[i] != '\0'; i++) 
// 							out[len++] = s[i];
// 						break;
// 					case 'x':
// 						unsigned int unum = va_arg(ap, unsigned int);
// 						if(unum == 0) {
// 							out[len++] = '0';
// 							break;
// 						}
// 						for(num_len = 0; unum; unum >>= 4, num_len++)
// 							buf[num_len] = NUM_CHAR[unum & 0xf];
// 						for(int i = num_len - 1; i >= 0; i--)
// 							out[len++] = buf[i];
// 						break;
// 					case 'p':
// 						out[len++] = '0'; out[len++] = 'x';
// 						uint32_t address = va_arg(ap, uint32_t);
// 						for(num_len = 0; address; address /= 16, num_len++)
// 							buf[num_len] = NUM_CHAR[address % 16];
// 						for(int i = num_len - 1; i >= 0; i--)
// 							out[len++] = buf[i];
// 						break;
// 				}
// 				break;
// 			case '\n':
// 				out[len++] = '\n';
// 				break;
// 			case '\r':
// 				out[len++] =  '\r';
// 				break;
// 			case '\t':
// 				out[len++] = '\t';
// 				break;
// 			default:
// 				out[len++] = *fmt;
// 		}
// 		fmt++;
// 	}
// 	out[len] = '\0';
// 	return len;
// }

  
// //out为输出字符串的缓冲区，fmt表示格式化字符串，...表示可变参数列表
// int sprintf(char *out, const char *fmt, ...) {
//   assert(out);

//   va_list args;
//   int i;

//   va_start(args, fmt);   //va_start宏初始化可变参数列表，将fmt和args传入
//   i = vsprintf(out, fmt, args); //vsprintf函数执行格式化字符串写入操作，返回写入的字符数
//   va_end(args);   //va_end宏结束可变参数列表的处理，以释放相关资源

//   return i;   //返回写入到输出字符串中的字符数
// }


// int printf(const char *fmt, ...) {
//   //panic("Not implemented");
//   int i;
//   char buf[256];

//   memset(buf, 0, sizeof(buf));

//   va_list args;
//   va_start(args, fmt);
//   i = vsprintf(buf, fmt, args);
//   va_end(args);

//   char *tmp = buf;
//   while(*tmp != 0){
//     putch(*tmp);
//     tmp++;
//   }

//   return i;
// }


// int snprintf(char *out, size_t n, const char *fmt, ...) {
//   panic("Not implemented");
// }

// int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
//   panic("Not implemented");
// }

// #endif


#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define MAXDEC 64
static char *__out;
void sputch(char ch){*__out++ = ch;}

int vprintf( void(*gputch)(char) , const char *fmt, va_list ap){
	int i;
	bool in_format = false;
	int long_flags = 0;
	int pos = 0;
	for( ;*fmt != '\0';fmt++){
		if(*fmt != '%' && in_format == false){
			gputch(*fmt);pos++;
		}
		else{
			if(in_format == false && (*fmt == '%')){
				fmt++;
				in_format = true;
			}
			switch(*fmt){
				case 'l':  //para
					long_flags += 1;
					break;
				case 's':  //%s
					char *s;
					assert(long_flags == 0);
					s = va_arg(ap , char *);
					for(i = 0; s[i] != '\0'; i++){
						gputch(s[i]);pos++;
					}
					in_format = false;
					break;
				case 'c':  //%c
					int c;
					assert(long_flags == 0);
					c = va_arg(ap , int);
					gputch((char)c);pos++;
					in_format = false;
					break;
				case 'd':{//%d
					assert(long_flags <= 2);
					int64_t d = 0;
					if(long_flags == 2)    //get d
						d = va_arg(ap , int64_t);
					else
						d = va_arg(ap , int32_t);

					if(d < 0){
						d = -d;
						gputch('-');pos++;
					}
					if(d == 0){
						gputch('0');pos++;
					};
					char invert[MAXDEC];
					i = 0;
					for( ; d != 0 ; i++ , d/=10){
						invert[i] = d%10 + '0';
					}
					for(i-=1 ;i >= 0 ; i--){
						gputch(invert[i]);pos++;
					}
					long_flags = 0;
					in_format = false;
					break;
					}
				case 'u':{  //%u
					uint64_t u = 0;
					assert(long_flags <= 2);
					if(long_flags == 2)    //get d
						u = va_arg(ap , uint64_t);
					else
						u = va_arg(ap , uint32_t);

					if(u == 0){
						gputch('0');pos++;
					};
					char invert[MAXDEC];
					i = 0;
					for( ; u != 0 ; i++ , u/=10){
						invert[i] = u%10 + '0';
					}
					for(i-=1 ;i >= 0 ; i--){
						gputch(invert[i]);pos++;
					}
					long_flags = 0;
					in_format = false;
					break;
					}
				case '%':
					gputch('%');
					in_format = false;
					break;
			}
		}
	}
	return pos;
}

int printf(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	int res = vprintf(putch , fmt , ap);
	va_end(ap);
	return res;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	__out = out;
	int res = vprintf(sputch , fmt , ap);
	sputch('\0');
	va_end(ap);
	return res++;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
