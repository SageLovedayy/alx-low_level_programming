#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to new table, NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int i;

	/*allocate memory for hash table structure*/
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
	{
		return (NULL);
	}


	/*allocate memory for array of hash nodes*/
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	new_table->size = size;

	/*initialize each element of thea array to NULL*/
	for (i = 0; i < size; i++)
	{
		new_table->array[i] = NULL;
	}

	return (new_table);

}

