#include "main.h"

/**
 * _pow_recursion - returns value of x raised to the power of y
 * @x: value to be raised
 * @y: power to raise to
 * Return: x raised to power of y, -1 if y is less than 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
