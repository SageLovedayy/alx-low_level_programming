#include <stdio.h>

/**
 * add - adds two integers
 * @a: First integer
 * @b: Second integer
 * Return: result of operation
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - gets difference between two integers
 * @a: First integer
 * @b: Second integer
 * Return: result of operation
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiplies two integers
 * @a: First integer
 * @b: Second integer
 * Return: result of operation
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - divides one one integers by another
 * @a: First integer
 * @b: Second integer
 * Return: result of operation
 */
int div(int a, int b)
{
	if (b != 0)
		return (a / b);

	fprintf(stderr, "Error: Division by zero\n");
	return (0);
}


/**
 * mod - gets teh remainder of division of two integers
 * @a: First integer
 * @b: Second integer
 * Return: result of operation
 */
int mod(int a, int b)
{
	if (b != 0)
		return (a % b);

	fprintf(stderr, "Error: Division by zero\n");
	return (0);
}
