#include "3-calc.h"

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

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (strcmp(ops[i].op, s) == 0) /*compares the value of ops[i].op and s returning 0 if they match*/
			return (ops[i].f); /*returns the corresponding function if there is a match*/
	}

	return (NULL); /*returns NULL if no operator is found*/
}
