#include "3-calc.h"

int main (int argc, char *argv[])
{
	int operand1, operand2, result;
	char *operator;

	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	operand1 = atoi(argv[1]);
	operator= argv[2];
	operand2 = atoi(argv[3]);

	operation = get_op_func(operator);

	if (operation == NULL || operator[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	result = operation(operand1, operand2);
	printf("%d\n", result);

	return (0);
}
