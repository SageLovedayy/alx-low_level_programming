#include "main.h"

/**
 * print_line - draws a straight line in terminal
 * @n: number of times the character _ is printed
 */
void print_line(int n)
{
	if (n > 0)
	{
		int i = 1;

		while (i <= n)
		{
			_putchar('_');
			i++;
		}
		_putchar('\n');
	}
	else
	{
		_putchar('\n');
	}
}
