#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void stringWriter(char *c, int *sum);
void stringExactWriter(char *c, int *sum);
void reverseString(char* str, int len);
int countDigits(long int x, unsigned int base);
char *convertNumber(long int x);
char *convertUnsignedNum(long int x);
char *convertToOct(long int x);
char *convertToHex(long int x, int upper);
char *convertToBin(long int x);

#endif
