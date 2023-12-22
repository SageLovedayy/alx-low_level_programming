#include "hash_tables.h"

/**
 * hash_table_print - prints the key-value pairs in the hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, comma = 0;
	hash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			if (comma == 1)
				printf(", ");

			printf("'%s': '%s'", current->key, current->value);

			/*check if there is another node in the list */

			current = current->next;

			comma = 1;
		}
	}

	printf("}\n");
}
