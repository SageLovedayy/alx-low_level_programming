#include "3-calc.h"
#include <stdio.h>

/**
* op_add - adds two integers
* @a: integer
* @b: integer
* Return: sum of integers
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
* op_sub - calculates difference between two integers
* @a: integer
* @b: integer
* Return: difference
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
* op_mul - multiplies two integers
* @a: integer
* @b: integer
* Return: result
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
* op_div - divides an integer by another
* @a: integer
* @b: integer
* Return: result
*/
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
* op_mod - returns the remainder of a division
* @a: integer
* @b: integer
* Return: result
*/
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
