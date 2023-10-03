#include "main.h"
#include <stdlib.h>

/**
* my_strlen - returns length of a string
* @str: input string
* Return: length of string
*/
int my_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
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
* argstostr - prints arguments as strings
* @ac: number of arguments
* @av: arguments
* Return: concatenated string on success, null on failure
*/
char *argstostr(int ac, char **av)
{
	int total_length, i, position;
	char *concatenated;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}



	total_length = i = position = 0;

	for (i = 0; i < ac; i++)
	{
		total_length += my_strlen(av[i]) + 1;
	}

	concatenated = malloc(total_length + 1);
	if (concatenated == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		my_strcpy(concatenated + position, av[i]);
		position += my_strlen(av[i]);
		concatenated[position] = '\n';
		position++;
	}

	concatenated[total_length] = '\0';

	return (concatenated);
}
