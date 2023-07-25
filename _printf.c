#include "main.h"
/**
 * _printf- prints any function
 * @format:format strig
 * Return: bytes of char
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	char *i;
	va_list ap;
	char *c, *start;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		/*init_par(&par, ap);*/
		if (*c != '%')
		{
			sum += _putchar(*c);
			continue;
		}

		start = c;
		c++;
		switch (*c)
		{
			case 'c':
				*i = (char) va_arg(ap, int);
				_putchar(*i);
				sum++;
				break;
			case 's':
				i = va_arg(ap, char *);
				stringWriter(c, &sum);
				break;
			case 'i':
				stringWriter(convert(va_arg(ap, int)), &sum);
				break;
			default:
				_putchar('%');
				_putchar(*start);
		}
	}

	va_end(ap);
	return (sum);
}

void stringWriter(char *c, int *sum)
{
	for (; *c != '\0'; c++)
	{
		_putchar(*c);
		*sum += 1;
	}
}

char *convert(int x)
{
	char *c;
	int i = 0, negative = 0, temp;

	if (x == 0)
		return (char *) '0';

	if(x < 0)
	{
		negative = 1;
		x *= -1;
	}

	temp = x;

	while (temp > 0)
	{
		temp /= 10;
		i++;
	}

	c = malloc(sizeof(char) * (i + negative + 1));

	i = 0;
	while (x > 0)
	{
		c[i++] = (x % 10) + '0';
		x /= 10;
	}

	if (negative)
	{
		c[i++] = '-';
	}

	reverseString(c, i);
	return c;
}

void reverseString(char* str, int len) {
	int i;
	char temp;

	for (i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}
