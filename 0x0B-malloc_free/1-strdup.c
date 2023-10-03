#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to newly allocated space in memory
 * @str: string given as parameter
 * Return: null if str is null, 0 on success
 */
char *_strdup(char *str)
{
	int i, j;

	char *newstr;

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	newstr = malloc(sizeof(char) * (i + 1));

	if (newstr == NULL)
	{
		return (NULL);
	}

	while (j <= i)
	{
		newstr[j] = str[j];
		j++;
	}

	return (newstr);
}
