#include "hash_tables.h"

/**
 * hash_table_print - prints the key-value pairs in the hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;

	if (ht == NULL)
		return;

	printf("{")
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			printf("'%s': '%s'", current->key, current->value);

			/*check if there is another node in the list */
			if (current->next != NULL)
				printf(", ");

			current = current->next;
		}
	}

	printf("}\n");
}
