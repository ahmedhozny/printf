#include "main.h"
/**
 * _printf- prints any function
 * @format:format strig
 * Return: bytes of char
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	varlist ap;
	char *c, *start;
	par_t par = par_init;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_par(&par, ap);
		if (*p != '%')
		{
			sum += _putchar(*c);
			continue;
		}
		start = c;
		c++;
		while (get_flags(c, &par))
		{
			p++;
		}
		c = get_width(c, &par, ap);
		c = get_precision(c, &par, ap);
		if (!get_modifier(c, &par))
		p++;
		if (!get_specifier(c))
			sum += print(start, c, par.l_modifier || par.h_modifier ? c - 1 : 0);
		else
			sum += get_print(c, ap, &par);
	}
	_putchar(buff);
	va_end(ap);
	return (sum);
}
