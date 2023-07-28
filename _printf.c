#include "main.h"
/**
 * _printf- prints any function
 * @format: format strig
 * Return: bytes of char
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *c, *start;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if ((format[0] == '%') && (format[1] == ' ') && !format[2])
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
				_putchar(va_arg(ap, int));
				sum++;
				break;
			case 's':
				stringWriter(va_arg(ap, char *), &sum);
				break;
			case 'i':
			case 'd':
				stringWriter(convertNumber(va_arg(ap, int)), &sum);
				break;
			case '%':
				_putchar('%');
				sum++;
				break;
			case 'u':
				stringWriter(convertUnsignedNum(va_arg(ap, unsigned int)), &sum);
				break;
			case 'o':
				stringWriter(convertToOct(va_arg(ap, unsigned int)), &sum);
				break;
			case 'x':
				stringWriter(convertToHex(va_arg(ap, unsigned int), 0), &sum);
				break;
			case 'X':
				stringWriter(convertToHex(va_arg(ap, unsigned int), 1), &sum);
				break;
			default:
				_putchar(*start);
				_putchar(*c);
				sum += 2;
		}
	}

	va_end(ap);
	return (sum);
}

/**
 * stringWriter -prints a string
 * @c: character to print
 * @sum: reference to sum
 */
void stringWriter(char *c, int *sum)
{
	for (; *c != '\0'; c++)
	{
		_putchar(*c);
		*sum += 1;
	}
}
