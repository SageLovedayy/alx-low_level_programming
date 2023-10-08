#include "main.h"
#include "stdlib.h"

/**
* _realloc - reallocates memory block using malloc and free
* @ptr: pointer to memory previously allocated
* @old_size: size of the allocated space for ptr
* @new_size: new size of new memory block
* Return: pointer to newly allocated memory on success
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	void *ptr2;
	unsigned int i;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	ptr2 = malloc(new_size);

	if (ptr2 == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < old_size && i < new_size; i++)
	{
		((char *)ptr2)[i] = ((char *)ptr)[i];
	}

	free(ptr);

	return (ptr2);
}
