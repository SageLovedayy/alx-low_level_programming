#include "main.h"
#include <stdlib.h>

/**
* my_strlen - calculates length of a string
* @c:string
* Return: length of string
*/
int my_strlen(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
* my_strcpy - copies one string to another
* @dest: destination string
* @src: source string
*/
void my_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

/**
* string_nconcat - concatenates two strings
* @s1: string
* @s2: string
* @n: number of bytes to be copied from s2
* Return: length of string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, total_len, i;
	char *concatenated;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	len1 = (my_strlen(s1));
	len2 = (my_strlen(s2));

	if (n >= len2)
	{
		n = len2;
	}

	total_len = len1 + n;

	concatenated = malloc(total_len + 1);

	if (concatenated == NULL)
	{
		return (NULL);
	}

	my_strcpy(concatenated, s1);

	for (i = 0; i < n; i++)
	{
		concatenated[len1 + i] = s2[i];
	}

	concatenated[total_len] = '\0';

	return (concatenated);
}
