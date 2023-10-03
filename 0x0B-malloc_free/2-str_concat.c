#include "main.h"
#include <stdlib.h>

/**
* str_concat - concatenates two string
* @s1: string
* @s2: string
* Return: concatenated string, null on error
*/
char *str_concat(char *s1, char *s2)
{
	int lenstr1, lenstr2, i, j;
	char *concatstr;

	i = j = lenstr1 = lenstr2 = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[lenstr1] != '\0')
	{
		lenstr1++;
	}
	while (s2[lenstr2] != '\0')
	{
		lenstr2++;
	}
	concatstr = malloc(lenstr1 + lenstr2 + 1);

	if (concatstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < lenstr1; i++)
	{
		concatstr[i] = s1[i];
	}
	for (j = 0; j < lenstr2; j++)
	{
		concatstr[i + j] = s2[j];
	}

	concatstr[i + lenstr2] = '\0';
	return (concatstr);
}
