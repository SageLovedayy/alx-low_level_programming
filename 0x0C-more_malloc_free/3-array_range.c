#include "main.h"
#include <stdlib.h>

/**
* array_range - creates an array of integers
* @min: lower boundary
* @max: upper boundary
* Return: pointer to created array
*/
int *array_range(int min, int max)
{
	int range;
	int *ptr;
	int i;



	if (min > max)
	{
		return (NULL);
	}

	range = (max - min + 1);

	ptr = malloc(range * sizeof(int));

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < range; i++)
	{
		ptr[i] = min + i;
	}

	return (ptr);
}
