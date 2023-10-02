#include "main.h"

/**
 * *_strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: specified bytes
 * Return: concatenated string with only n bytes of second string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *dest_start = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	*dest = '\0';
	return (dest_start);
}
