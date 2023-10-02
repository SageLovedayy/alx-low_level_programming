#include <stdio.h>

/**
* main - prints all arguments it receives(one per line)
* @argc: number of arguments
* @argv: arguments themselves
*/

void main(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
}
