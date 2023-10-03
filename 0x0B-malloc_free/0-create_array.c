#include "main.h"
#include <stdlib.h>

/**
* create_array - creates an array of chars, init with a specific char.
* @size: size of array
* @c: char to be assigned
* Return: NULL if size is 0 and on failure
*/

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	i = 0;

	str = malloc(sizeof(char) * size);

	if (str == NULL || size == 0)
	{
		return (NULL);
	}

	while (i < size)
	{
		str[i] = c;
		i++;
	}

	return (str);
}
