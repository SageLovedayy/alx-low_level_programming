#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of triangle
 */
void print_triangle(int size)
{
	if (size <= 0)

	{
		_putchar('\n');
	}

	else 
	{
		int a;
		int b;

		while (size > 0)
		{

			for (a = 1; a < size; a++)
			{
				_putchar(' ');
			}

			for (b = size; b <= size; b++)
			{
				_putchar('#');
			}

			_putchar('\n');

			size--;
		}
	}
}
	
