#include <stdio.h>

/**
 * main - prints name of file program is compiled from
 * Return: 0 on Success
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
