#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int tens1, ones1, tens2, ones2, tens3, ones3, tens4, ones4;

	for (tens1 = 0; tens1 <= 9; tens1++)
	{
		for (ones1 = 0; ones1 <= 9; ones1++)
		{
			for (tens2 = 0; tens2 <= 9; tens2++)
			{
				for (ones2 = 0; ones2 <= 9; ones2++)
				{
					if (tens2 < tens1 || (tens2 == tens1 && ones2 <= ones1))
					{
						continue;
					}

								{
					putchar(tens1 + '0');
					putchar(ones1 + '0');
					putchar(' ');
					putchar(tens2 + '0');
					putchar(ones2 + '0');

					if (!(tens1 == 9 && ones1 == 9 && tens2 == 9 && ones2 == 9))
					{
						putchar(',');
						putchar(' ');
					}

					for (tens3 = 0; tens3 <= 9; tens3++)
					{
						for (ones3 = 0; ones3 <= 9; ones3++)
						{
							if (tens3 < tens2 || (tens3 == tens2 && ones3 <= ones2))
							{
								continue;
							}

							putchar(tens1 + '0');
							putchar(ones1 + '0');
							putchar(' ');
							putchar(tens2 + '0');
							putchar(ones2 + '0');
							putchar(tens3 + '0');
							putchar(ones3 = '0');
				}
			}
		}
	}

	putchar('\n');
	return (0);
}
