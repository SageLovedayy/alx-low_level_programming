#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
* main - adds positive numbers
* @argc: number of arguments
* @argv: argument
* Return: 0 if there is a symbol in argument
*/
int main(int argc, char *argv[])
{

	/**
	*if (argc < 2)
	*{
	*	printf("0\n");
	*}
	*/

	int i, add = 0;


	for (i = 1; i < argc; i++)
	{
		int j;

		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		int num = atoi(argv[i]);

		add += num;
	}

	printf("%d\n", add);
}
