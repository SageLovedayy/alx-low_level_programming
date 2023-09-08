#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n <= 15; n++)
	{
		if (n <= 9)
		{
			putchar(n + '0');
		}
		else
		{
			putchar('a' + (n - 10));
		}
	}
	putchar('\n');
	return (0);
}
