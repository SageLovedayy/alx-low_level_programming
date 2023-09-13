#include "main.h"

/**
 * print_sign - prints the sign of a number
 * returns 1 and prints + if greater than 0
 * returns 0 and prints 0 if greater than 0
 * returns -1 and prints - if less than 0
 * @n: number
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar(48);
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
