#include "main.h"

/**
 * *cap_string - capitalizes all words of a string
 * @str: string
 * Return: capitalized string
 */
char *cap_string(char *)
{
	char *capitalize_next = 1;

	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n' || *str == ',' || *str == ';' ||
		*str == '.' || *str == '!' || *str == '?' || *str == '"' || *str == '(' ||
		*str == ')' || *str == '{' || *str == '}')
		{
			capitalize_next = 1;
		}
		else if (isalpha(*str)) 
		{
			if (capitalize_next)
			{
				*str =toupper(*str);
				capitalize_next = 0;
			}
			else
			{
				*str = tolower(*str);
			}
		}
		str++;
	}
	return str;
}
