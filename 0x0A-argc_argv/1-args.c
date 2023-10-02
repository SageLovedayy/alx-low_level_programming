#include <stdio.h>

/**
* main - prints the number of arguments passed into function
* @argc: number of arguments
* @argv: argumments themselves
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", (argc - 1));
	return (0);
}
