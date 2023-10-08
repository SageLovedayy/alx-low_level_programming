#include "main.h"
#include <stdlib.h>

/**
* _calloc - allocates memory for an array using malloc
* @nmemb: number of elements
* @size: number of bytes
* Return: pointer to allocated memory
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int n;
	unsigned int i;
	unsigned char *char_ptr;
	void *ptr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	n = nmemb * size;
	ptr = malloc(n);

	if (ptr == NULL)
	{
		return (NULL);
	}



	char_ptr = (unsigned char *)ptr;

	for (i = 0; i < n; ++i)
	{
		char_ptr[i] = 0;
	}

	return (ptr);

}
