#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdlib.h>
#include <stdarg.h>

#define _PRAMA_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

/**
 *  struct parameters - struct to get the pramters
 *  @unsign : unsigned par
 *  @plus :plus flag
 *  @space: space flag
 *  @hashtag:hashtag flag
 *  @zero :zero flag
 *  @minus :minus flag
 *  @width :field width specified
 *  @precision: field precision specified
 *  @h_modif: field h_modifier specified
 *  @l_modif: field l_modifier specified
 */
typedef struct parameters
{
	unsigned int unsign :1;
	unsigned int plus :1;
	unsigned int space :1;
	unsigned int hashtag :1;
	unsigned int zero :1;
	unsigned int minus :1;
	unsigned int width :1;
	unsigned int precision :1;
	unsigned int h_modif :1;
	unsigned int l_modif :1;
} par_t;

int _printf(const char *format, ...);
int _putchar(char c);
void stringWriter(char *c, int *sum);
<<<<<<< HEAD
char *convert(int x);
void reverseString(char *str, int len);
int get_flag(char *r, par_t *par);
int get_mdif(char *r, par_t *par);
=======
void stringExactWriter(char *c, int *sum);
void reverseString(char* str, int len);
int countDigits(long int x, unsigned int base);
char *convertNumber(int x);
<<<<<<< HEAD
char *convertUnsignedNum(unsigned int x);
char *convertToOct(unsigned int x);
char *convertToHex(unsigned int x, int upper);
<<<<<<< HEAD
>>>>>>> 7ecc4ba0c17a443c5b561af62ddeb0a29ac5dc35
=======
char *convertToBin(unsigned int x);
=======
char *convertUnsignedNum(long int x);
char *convertToOct(long int x);
char *convertToHex(long int x, int upper);
char *convertToBin(long int x);
>>>>>>> 0e999029d822b5d02c4035e77f71f7c1507fff33

>>>>>>> d69a21d72c5bae70de3cb72d143ff19b2af950a5
#endif
