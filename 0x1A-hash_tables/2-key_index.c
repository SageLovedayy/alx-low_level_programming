#include "hash_tables.h"

/**
 * key_index - gives index of a key
 * @key: key
 * @size: size of array
 * Return: index of key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long hash_value;
	/*use the hash_djb2 funtion to generate the hash value*/
	hash_value = hash_djb2(key);
	/*calculate the index by taking remainder*/
	return (hash_value % size);
}
