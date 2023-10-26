#include "main.h"

/**
 * flip_bits - returns number of bits you will need
 * to flip to get from one number to another.
 * @n: number one
 * @m: number two
 * Return: Number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result;
	unsigned int count = 0;

	xor_result = n ^ m;

	/*count number of set bits in xor_result*/
	while (xor_result > 0)
	{
		/*increment count if the least significant bit is set (1) */
		count += xor_result & 1;
		/* Right shift xor_result to check the next bit */
		xor_result >>= 1;
	}

	return (count);
}

