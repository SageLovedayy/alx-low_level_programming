#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


/**
* is_valid_number - checks if argument is not a number
* @str: input string
* Return: 0 if digit, 1 otherwise
*/
int is_valid_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}
	return (1);
}

/**
* mystrlen - returns the length of a string
* @str: string
* Return: string length
*/
int mystrlen(char *str)
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

/**
* multiply_numbers - multiplies two integers
* @num1: integer
* @num2: integer
*/
void multiply_numbers(char *num1, char *num2)
{
	int len1, len2, total_len, i, a, *result, digit1, digit2, carry;

	len1 = mystrlen(num1);
	len2 = mystrlen(num2);
	total_len = len1 + len2 + 1;
	result = malloc(total_len * sizeof(int));
	if (result == NULL)
		exit(1);
	for (i = 0; i <= len1 + len2; i++)
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
			result[len1 + len2 + 1] += carry;
		}
	}
	for (i = 0; i < total_len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
}


/**
* main - Uses multiply_numbers function on two arguments
* @argc: number of arguments
* @argv:  argument vectors
* Return: 0 on success, 98 on failure
*
*/
int main(int argc, char *argv[])
{

	char *num1, *num2;

	num1 = argv[1];
	num2 = argv[2];

	if (argc != 3 || !is_valid_number(num1) || !is_valid_number(num2))
	{
		printf("Error\n");
		exit(98);
	}

	multiply_numbers(num1, num2);
	return (0);
}
