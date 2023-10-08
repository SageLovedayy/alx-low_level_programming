#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int is_valid_number(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}

		str++;
	}
	return (1);
}

int mystrlen (char *str)
{
	int i;
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int main(int argc, char *argv[])
{
	int len1, len2, total_len, i, a;
	int *result, digit1, digit2, carry;
	char *num1, *num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	/**
	* num1 = atoi(argv[1]);
	* num2 = atoi(argv[2]);
	* result = (num1 * num2);
	*/

	num1 = argv[1];
	num2 = argv[2];
	len1 = mystrlen(num1);
	len2 = mystrlen(num2);
	total_len = len1 + len2;

	result = malloc((total_len + 1) * sizeof(int));
	if (result == NULL)
	{
		exit(1);
	}

	for (i = 0; i <= total_len; i++)
	{
		result[i] = 0;
	}

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1[len1] - '0';
		carry = 0;

		for (len2 = mystrlen(num2) - 1; len2 >= 0; len2--)
		{
			digit2 = num2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
		{
			result[total_len + 1] += carry;
		}
	}

	for (i = 0; i < total_len; i++)
	{
		if (result[i])
		{
			a = 1;
		}
		if (a)
		{
			_putchar(result[i] + '0');
		}
	}

	if (!a)
	{
		_putchar('0');
	}

	_putchar('\n');
	free(result);

	return (0);
}
