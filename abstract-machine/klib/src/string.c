#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

//计算字符串长度
size_t strlen(const char *s) {
	if (s == NULL) {
    	return 0;
  	}
  	size_t n = 0;
  	while(s[n] != '\0') {
		n++;
  	}
  	return n;
}
 
//复制字符串
char *strcpy(char *dst, const char *src) {
  	if (src == NULL || dst == NULL) { 
    	return dst;
  	}
	//assert( dst && src );
  	char *res = dst;
  	do {
    	*dst ++ = *src ++;
  	} while(*src != '\0');
	*dst = '\0';
  	return res;
}

 
//一部分复制到目标字符串
/*
char *strncpy(char *dst, const char *src, size_t n) {
	assert( dst && src && n >= 0);
	size_t i;
  	for(i = 0; src[i] != '\0'; i++){
    	dst[i] = src[i];
  	}
	  
  	dst[i] = '\0';
  	return dst;
}
*/
  
char *strncpy(char *dst, const char *src, size_t n) {   //PASS!
	assert( dst && src && n >= 0);
	char *tmp = dst;
	while( n && (*dst++ = *src++) ){
            n--;
        }
	if(n > 0){
		while(--n){
			*dst++ = '\0';
		}
	}
	return tmp;
}
    
 
//用于将一个字符串追加到另一个字符串的末尾
/*
char *strcat(char *dst, const char *src) {
	assert(dst && src);
  	size_t i = 0;
  	while(dst[i] != '\0'){
    	i++;
  	}
  	strcpy(dst + i, src);
  	return dst;
}
*/

char *strcat(char *dst, const char *src) {      //PASS!
	assert(dst && src);
	char *tmp = dst;
	while(*dst != '\0'){	//找到目标字符串的空字符指针位置
		dst ++;
	}
	while(*src != '\0'){	//一直加到空字符（不含‘\0’）
		*dst++ = *src++;
	}
	*dst = '\0';
	return tmp;
}

//比较字符串
/*
int strcmp(const char *s1, const char *s2) {
   size_t i = 0;
  while(s1[i] != '\0' && s2[i] != '\0')
  {
	  if(s1[i] > s2[i])
		  return 1;
	  if(s1[i] < s2[i])
		  return -1;
	  i++;
  }
  if(s1[i] != '\0' && s2[i] == '\0')
	  return 1;
  if(s1[i] == '\0' && s2[i] != '\0')
	  return -1;
  return 0;
 
}
*/

int strcmp(const char *s1, const char *s2) {    //PASS!
	assert(s1 != NULL && s2 != NULL);

	while( (*s1 == *s2) && (*s1 != '\0') ){
		s1 ++; s2++;
	}
	return *s1-*s2;
}



//比较字符串前几个字符
/*
int strncmp(const char *s1, const char *s2, size_t n) {

  	while(n--)
		{
			if(*s1 > *s2)
				return 1;
			if(*s1 < *s2)
				return -1;
			s1++;
			s2++;
		}
		return 0;
}
*/
int strncmp(const char *s1, const char *s2, size_t n) { //PASS!
	if(!n){
		return 0;
	}
	assert(s1 && s2);
	while( *s1 && (*s1 == *s2) && (--n) ){
		s1++; s2++;
	}
	return *s1 - *s2;
}

//指定的内存区设置为特定值
/*
void *memset(void *s, int c, size_t n) {
  char *ch = (char *) s;
  while(n-- > 0)
	  *ch++ = c;
  return s;
 
}
*/

void *memset(void *s, int c, size_t n) {        //PASS!
	assert(s != NULL && n >= 0);

	char *res = (char *)s;	//指向地址的指针
	while(n-- >0){
		*(char *)s++ = c;
	}
	return res;
}

//内存中移动数据,能处理内存区域重叠情况
void *memmove(void *dst, const void *src, size_t n) {
	assert(dst && src && n >= 0);
   	if(dst < src){
	  	char *d = (char *) dst;
	  	char *s = (char *) src;
	  	while(n--){
		  	*d = *s;
		  	d++;  s++;
	  	}
  	}
  	else{
	  	char *d = (char *) dst + n - 1;
	  	char *s = (char *) src + n - 1;
	  	while(n--){
		  	*d = *s;
		  	d--;  s--;
	  	}
  	}
  	return dst;
}
 
//复制内存区内容
/*
void *memcpy(void *out, const void *in, size_t n) {
	assert(out && in && n >= 0);
  	char *d = (char *) out;
  	char *s = (char *) in;
  	while(n--){
	  	*d = *s;
	  	d++;  s++;
  	}
  	return out;
}
*/

void *memcpy(void *out, const void *in, size_t n) {     //PASS!
	assert(out && in && n >= 0);
	int i=0;
	for( i=0; i < n; i++ ){
		*( (char*)out + i ) = *( (char*)in + i );
	}
	return out;
}

//比较两个内存内容
int memcmp(const void *s1, const void *s2, size_t n) {
	assert(s1 && s2 && n >= 0);
  	char * one = (char *)s1;
  	char * two = (char *)s2;
  	while(n--){
	  	if(*one > *two)
		  	return 1;
	  	if(*one < *two)
		  	return -1;
	  	one++;  two++;
  	}
  	return 0;
}


#endif