#include "main.h"

/**
 * *string_toupper - changes lowercase letters of string to uppercase
 * @str: string
 * Return: String of uppecase letters
 */
char *string_toupper(char *str)
{
	char *result = str;

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 'a' + 'A';
		}
		str++;
	}
	return (result);
}

