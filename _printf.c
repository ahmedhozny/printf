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
				stringWriter(convertNumber(va_arg(ap, long int)), &sum);
				break;
			case '%':
				_putchar('%');
				sum++;
				break;
			case 'b':
				stringWriter(convertToBin(va_arg(ap, long int)), &sum);
				break;
			case 'u':
				stringWriter(convertUnsignedNum(va_arg(ap, long int)), &sum);
				break;
			case 'o':
				stringWriter(convertToOct(va_arg(ap, long int)), &sum);
				break;
			case 'x':
				stringWriter(convertToHex(va_arg(ap, long int), 0), &sum);
				break;
			case 'X':
				stringWriter(convertToHex(va_arg(ap, long int), 1), &sum);
				break;
			case 'S':
				stringExactWriter(va_arg(ap, char *), &sum);
				break;
			case 'p':
<<<<<<< HEAD
<<<<<<< HEAD
				stringWriter(convertToHex(va_arg(ap, int), 1), &sum);
=======
				stringWriter("0x", &sum);
				stringWriter(convertToHex(va_arg(ap, unsigned int), 1), &sum);
>>>>>>> d69a21d72c5bae70de3cb72d143ff19b2af950a5
=======
				stringWriter("0x", &sum);
				stringWriter(convertToHex(va_arg(ap, long int), 0), &sum);
>>>>>>> 0e999029d822b5d02c4035e77f71f7c1507fff33
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
	if (!c)
		stringWriter("(null)", sum);

	while (!*c)
		c++;

	for (; *c != '\0'; c++)
	{
		_putchar(*c);
		*sum += 1;
	}
}

/**
 * stringWriter -prints a string
 * @c: character to print
 * @sum: reference to sum
 */
void stringExactWriter(char *c, int *sum)
{
<<<<<<< HEAD
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
=======
	char *x = "\\x";

	while (!*c)
		c++;
>>>>>>> 7ecc4ba0c17a443c5b561af62ddeb0a29ac5dc35

	for (; *c != '\0'; c++)
	{
<<<<<<< HEAD
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
=======
		if ((*c < 32) || (*c >= 127))
		{
			stringWriter(x, sum);
			stringWriter(convertToHex(*c, 1), sum);
			continue;
		}

		_putchar(*c);
		*sum += 1;
>>>>>>> 7ecc4ba0c17a443c5b561af62ddeb0a29ac5dc35
	}
}
