#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void stringWriter(char *c, int *sum);
char *convert(int x);
void reverseString(char* str, int len);
#endif
