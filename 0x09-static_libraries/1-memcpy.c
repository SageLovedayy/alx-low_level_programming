#include "main.h"

/**
 * _memcpy - copies n ytes from src to dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;

	while (n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (dest);
}
