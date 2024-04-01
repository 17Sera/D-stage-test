#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


size_t strlen(const char *s) {                  //PASS!
	assert(s != NULL);
	size_t len = 0;
	while( s[len] != '\0' ){
		len++;
	}
	return len;
}

char *strcpy(char *dst, const char *src) {      //PASS!
	assert( dst != NULL && src != NULL );

	char *tmp = dst;
	while( *src != '\0' ){
		*dst ++ = *src ++;
	}
	*dst = '\0';
	return tmp;	
}

char *strncpy(char *dst, const char *src, size_t n) {   //PASS!
	assert( dst != NULL && src != NULL && n >= 0);
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

char *strcat(char *dst, const char *src) {      //PASS!
	assert(dst != NULL && src != NULL);

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

int strcmp(const char *s1, const char *s2) {    //PASS!
	assert(s1 != NULL && s2 != NULL);

	while( (*s1 == *s2) && (*s1 != '\0') ){
		s1 ++; s2++;
	}
	return *s1-*s2;
}

int strncmp(const char *s1, const char *s2, size_t n) { //PASS!
	if(!n){
		return 0;
	}
	assert(s1 != NULL && s2 != NULL);
	while( *s1 && (*s1 == *s2) && (--n) ){
		s1++; s2++;
	}
	return *s1 - *s2;
}

void *memset(void *s, int c, size_t n) {        //PASS!
	assert(s != NULL && n >= 0);

	char *res = (char *)s;	//指向地址的指针
	while(n-- >0){
		*(char *)s++ = c;
	}
	return res;
}

void *memmove(void *dst, const void *src, size_t n) {   //PASS!
	assert(dst != NULL && src != NULL && n >= 0);
	void *res = dst;
	if(dst < src){
		while(n--){
			*(char*)dst = *(char*)src;
                        dst = (char*)dst + 1;
                        src = (char*)src + 1;
		}
	}
	else if(dst > src){
		while(n--){
                        *( (char*)dst + n ) = *( (char*)src + n );
		}
	}
	return res;
}

void *memcpy(void *out, const void *in, size_t n) {     //PASS!
	assert(out != NULL && in != NULL && n >= 0);
	int i=0;
	for( i=0; i < n; i++ ){
		*( (char*)out + i ) = *( (char*)in + i );
	}
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {  //PASS!
	assert(s1 != NULL && s2 != NULL && n >= 0);
	while( n-- && *(char*)s1 == *(char*)s2 ){
		s1 = (char *)s1 +1;
		s2 = (char *)s2 +1;
	}
	return ( *((unsigned char *)s1) - *((unsigned char *)s2) );
}




#endif
