#include "main.h"
#include "stdio.h"

/**
* binary_to_uint - converts binary to base 10
* @b: binary string of digits
* Return: number in base10, 0 on failure
*/
unsigned int binary_to_uint(const char *b)
{
	int count = 0;
	unsigned int result = 0;
	int power = 1;
	int i;

	if (b == NULL)
		return (0);

	while (b[count] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		count++;
	}

	if (count == 0)
		return (0);

	for (i = count - 1; i >= 0; i--)
	{

		if (b[i] == '1')
			result += power;

		power *= 2;
	}

	return (result);


}
