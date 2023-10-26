#include "main.h"

/**
* get_bit - returns value of a bit at a given index
* @n: bit
* @index: given index
* Return: value of bit at index, -1 on error
*/
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index;
	return ((n & mask) ? 1 : 0);
}
