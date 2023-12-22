#include "../main.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	unsigned long int num;
	int set = 1;

	while (set == 1)
	{
		printf("\nEnter base 10 number to convert: ");
		scanf("%lu", &num);

		//if (!isdigit(num))
		//{
		//	printf("Invalid input: Program exited\n");
		//	return (-1);
		//}

		printf("===============================\nBinary representation of %lu:\n", num);
		print_binary(num);
		printf("===============================\n");
		printf("1. Continue 0. Exit\n");
		scanf("%d", &set);
		printf("________________________________\n");
	}

	if (set != 1)
		printf("~Program exited\n");

	return (0);
}
