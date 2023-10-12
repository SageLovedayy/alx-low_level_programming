#include "function_pointers.h"

/**
* int_index- searches for an integer
* @array: array to search
* @size: number of elements in array
* @cmp: pointer to function for comparing values
* Return: index of located integer
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	i = 0;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}

	return (-1);
}
