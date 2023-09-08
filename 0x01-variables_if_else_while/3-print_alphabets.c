#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'a';
	char letterUpper = 'A';

	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}

	while (letterUpper <= 'Z')
	{
		putchar(letterUpper);
		letterUpper++;
	}

	putchar('\n');
	return (0);
}
