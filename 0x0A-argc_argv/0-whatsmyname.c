#include <stdio.h>

/**
* main - prints name of program, followed by a new line
* @argc: size of array, number of arguments
* @argv: arguments themselves
* Return: 0
*/
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", *argv);
	return (0);
}
