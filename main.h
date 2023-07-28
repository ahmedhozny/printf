#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void stringWriter(char *c, int *sum);
void reverseString(char* str, int len);
int countNumbers(unsigned int x);
int countDigits(unsigned int x, unsigned int base);
char *convertNumber(int x);
char *convertUnsignedNum(unsigned int x);
char *convertToOct(unsigned int x);
char *convertToHex(unsigned int x, int upper);

#endif
