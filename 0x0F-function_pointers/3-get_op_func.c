#include "3-calc.h"

/**
* get_op_func - compares input char operator and selects function
* @s: input
* Return: appropriate function for operator
*/
int (*get_op_func(char *s))(int, int)
{
	int i;

	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, s) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}

	return (NULL); /*returns NULL if no operator is found*/
}
