#include "main.h"

/**
* get_endianness - determine endianness of underlying system architecture
* Return: 0 if big endian, 1 if little endian
*/
int get_endianness(void)
{
	int num = 1;

	char *bytePtr = (char *)&num;

	return (*bytePtr == 1);
}
