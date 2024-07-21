#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

//将整数转换为指定进制的字符串形式，存储到指定的字符数组中
//转换后的字符串将存储在str指针所指向的内存空间 //num为要转换的数字 //base为要转换的进制
static char *number(char *str, int num, int base)  //返回指向转换后数字的下一个字符的指针
{
  assert( str && base );
  int tmp[100], i = 0;
  if(num < 0){        //处理负数，先在str指向处存负号
    *str++ = '-';
    num = -num;       //负数数值用绝对值（正数）处理
  }
  while( num ){         //不断取余、除法得到各个位上的数字，存在数组tmp
    tmp[i++] = num % base;
    num /= base;
  }
  i--;    //指针回退到转换后数字的最后一位


  while(i >= 0) {       //转为字符型数字
    *str++ = tmp[i--] + '0';  //将整数值(大于0的值)加上字符 '0' 的ASCII码值48---将整数转换为对应的字符
    }   
  return str;
}
  
//out为输出字符串的缓冲区，fmt表示格式化字符串，ap表示可变参数列表
int vsprintf(char *out, const char *fmt, va_list ap) {    
  assert(out);
  char *str = out; 
  const char *s;
  int base;   //进制
  int num;    //被格式化的数字

  for(; *fmt != '\0'; ++fmt){  
    if(*fmt != '%'){
      *str++ = *fmt;    //开头不是%---将该字符直接拷贝到输出字符串中
      continue;         //继续下一个字符的处理
    }

    ++fmt;              //当前字符为%，让指针指向%下一个字符

    base = 10;          //默认为10进制  

    switch(*fmt){       //据%后一个字符分情况
      case 'c':
        *str++ = (unsigned char) va_arg(ap, int);
        //从可变参数列表取出一个int型参数，转成unsigned char存入输出字符串中
        continue;
      case 's':
        s = va_arg(ap, char *);   //从可变参数列表取出一个char *型参数

        //for(int i = 0; s[i]; i++)
        //  *str++ = s[i];
        strcat(str, s);     //将该字符串拼接到输出字符串的末尾
        str += strlen(s);   //更新输出字符串的位置指针
        continue;

      case 'd':
        break;
        
      default:
        *str++ = '%';
        if(*fmt)
          *str++ = *fmt;
        else
          --fmt;    //防止溢出
        continue;
    }
    num = va_arg(ap, int);

    str = number(str, num, base); 
    // %d 调用number来进行格式化处理，更新输出字符串的位置指针
  }
  *str = '\0';       //循环结束，输出字符串末尾加\0
  return str - out;  //返回写入的字符数
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


int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif