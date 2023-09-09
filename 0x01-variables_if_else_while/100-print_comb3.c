#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	char tens, ones;

	for (tens = '0'; tens <= '9'; tens++)
	{
		for (ones = tens + 1; ones <= '9'; ones++)
		{
			putchar(tens);
			putchar(ones);
			if (tens < '8')
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
