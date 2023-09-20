#include "main.h"

/**
 * *_strncpy - function to concatenate two strings similarly to strncpy
 * @dest: destination string
 * @src: source string
 * @n: number of bytes
 * Return: concatenated string
 */
char *_strncpy(char *dest, const char *src, int n)
{
	char *dest_start = *dest;

	while (src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}

	return (dest_start);
}

