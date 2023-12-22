#include "hash_tables.h"

/**
* hash_table_set - adds or updates a key-value pair in the hash table
* @ht: hash table
* @key: key
* @value: value associateed with the key
* Return: 1 on success, 0 otherwise
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0); /*Invalid input parameters*/
	/*Get the index for the key using the hash function*/
	index = hash_djb2((const unsigned char *)key) % ht->size;
	/* check if the key already exists in the linked list*/
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			/* Key found, update value and return success */
			free(current->value);
			current->value = strdup(value);

			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}
	/* Key not found, create new node and add it to the beginning of the list*/
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
