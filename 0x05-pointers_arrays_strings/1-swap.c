#include "main.h"

/**
 * swap_int - swaps values of two integers
 * @a: first integer
 * @b: second integer
 * Return: swapped values
 */
void swap_int(int *a, int *b)
{
	int m = *a;
	*a = *b;
	*b = m;
}
