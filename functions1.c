#include "main.h"
#include <stdlib.h>

/**
 * convert -find the string that refer to the given integer
 * @x: character to print
 *
 * Return: string representing x
 */
char *convertNumber(int x)
{
	char *c;
	int negative = 0;

	if (x == 0)
		return (char *) '0';

	if (x < 0)
	{
		x -= 1;
		negative = 1;
	}

	c = convertUnsignedNum((long int) x);

	if (negative)
		c[0] = '-';

	return (c);
}

char *convertUnsignedNum(long int x)
{
	char *c;
	int i, n;

	if (x == 0)
		return (char *) '0';

	n = countDigits(x, 10);

	c = malloc(sizeof(char) * (n + 1));
	if (!c)
	{
		free(c);
		return (0);
	}

	for (i = 0; i < n; i++)
	{
		c[n - i] = (x % 10) + '0';
		x /= 10;
	}

	return (c);
}

int countDigits(long int x, unsigned int base)
{
	int i = 0;

	if (x == 0)
		return (1);

	while (x > 0)
	{
		x /= (long) base;
		i++;
	}

	return (i);
}

/**
 * reverseString -reverses a given string
 * @str: pointer to a string
 * @len: length of the given string
 */
void reverseString(char* str, int len)
{
	int i;
	char temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

char *convertToBin(long int x)
{
	char *c;
	int i, n;

	if (x == 0)
		return ((char *) '0');

	n = countDigits(x, 2);

	c = malloc(sizeof(char) * (n));
	if (!c)
	{
		free(c);
		return (0);
	}

	for (i = 0; i <= n; i++)
	{
		c[n - i - 1] = (x % 2) + '0';
		x /= 2;
	}

	return (c);
}

char *convertToOct(long int x)
{
	char *c;
	int i, n;

	if (x == 0)
		return ((char *) '0');

	n = countDigits(x, 8);

	c = malloc(sizeof(char) * (n + 1));
	if (!c)
	{
		free(c);
		return (0);
	}

	for (i = 0; i < n; i++)
	{
		c[n - i] = (x % 8) + '0';
		x /= 8;
	}

	return (c);
}

char *convertToHex(long int x, int upper)
{
	char *c;
	int i, n;

	if (x == 0)
		return ((char *) '0');

	upper = upper ? 55 : 87;
	n = countDigits(x, 16);

	c = malloc(sizeof(char) * (n + 1));
	if (!c)
	{
		free(c);
		return (0);
	}

	for (i = 0; i < n; i++)
	{
		c[n - i] = (x % 16) > 9 ? (x % 16) + upper : (x % 16) + '0';
		x /= 16;
	}

	return (c);
}
