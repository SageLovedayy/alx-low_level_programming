#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * returns 1 if alphabet
 *@c: character
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
