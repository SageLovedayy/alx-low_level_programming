#include <stdio.h>
#include <stdlib.h>


/**
* main - prints result of multiplication of arguments
* @argc: number of arguments
* @argv: argumments themselves
* Return: 0 if successful, 1 if not
*/



int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);

		printf("%d\n", (num1 * num2));
		return (0);
	}

	printf("%s\n", "Error");
	return (1);
}
