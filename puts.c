#include <unistd.h>

/**
 * _putchar -function that takes character type and write it to the terminal
 * @c: character to print
 *
 * Return: On success 1, -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}