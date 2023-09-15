#include "main.h"
#include <stdio.h>

/**
 * main - prints numbers 1 to 100, followed by a new line
 * print Fizz for multiples of three instead of the number
 * print Buzz for multiples of five
 * print FizzBuzz for multiples of both thee and five
 * Return: 0 on success
 */
int main(void)
{
	int a;

	for (a = 1; a <= 100; a++)
	{

		if (a % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (a % 5 == 0)
		{
			printf("Buzz ");
		}
		else if (a % 3 == 0 && a % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else
		{
			printf("%d ", a);
		}
	}
	putchar('\n');
	return (0);
}
