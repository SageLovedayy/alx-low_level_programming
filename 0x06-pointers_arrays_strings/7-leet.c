#include <stdio.h>
#include <string.h>

char *leet(char *str)
{
	char *ptr = str; // Pointer to the input string

	while (*ptr != '\0') {
		// Check if the current character is an 'a' or 'A'
		// and replace it with '4' if true
		if (*ptr == 'a' || *ptr == 'A') {
			*ptr = '4';
		}
		// Check if the current character is an 'e' or 'E'
		// and replace it with '3' if true
		else if (*ptr == 'e' || *ptr == 'E') {
			*ptr = '3';
		}
		// Check if the current character is an 'o' or 'O'
		// and replace it with '0' if true
		else if (*ptr == 'o' || *ptr == 'O') {
			*ptr = '0';
		}
		// Check if the current character is a 't' or 'T'
		// and replace it with '7' if true
		else if (*ptr == 't' || *ptr == 'T') {
			*ptr = '7';
		}
		// Check if the current character is an 'l' or 'L'
		// and replace it with '1' if true
		else if (*ptr == 'l' || *ptr == 'L') {
			*ptr = '1';
		}

		ptr++; // Move to the next character
	}

	return (str);
