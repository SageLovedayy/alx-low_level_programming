#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first stirng
 * @s2: second string
 * Return: difference between both strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}