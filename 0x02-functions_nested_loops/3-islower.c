#include "main.h"

/**
 * _islower - checksif char is lowercase
 * Return: 1 if lowercase and 0 if uppercase
 * @c: char
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
