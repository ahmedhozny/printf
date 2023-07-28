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
				stringWriter(convert(va_arg(ap, int)), &sum);
				break;
			case '%':
				_putchar('%');
				sum++;
				break;
			default:
				_putchar(*start);
				_putchar(*c);
				sum += 2;
		}
		while (get_flag(c, &par))
		{
			c++;
		}
		if (get_modif(c, &par))
			c++;
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

/**
 * convert -find the string that refer to the given integer
 * @x: character to print
 *
 * Return: string representing x
 */
char *convert(int x)
{
	char *c;
	int i = 0, negative = 0, temp;

	if (x == 0)
		return ((char *) '0');

	if (x < 0)
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
	return (c);
}

/**
 * reverseString -reverses a given string
 * @str: pointer to a string
 * @len: length of the given string
 */
void reverseString(char *str, int len)
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
