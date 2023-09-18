#include "main.h"

/**
 * print_rev - prints string in reverse
 * @s: input string
 */
void print_rev(char *s)
{
	int a = 0;
	int b = 0;

	while (*s != 0)
	{
		a++;
		s++;
	}
	s--;
	for (b = a; b > 0; b--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
