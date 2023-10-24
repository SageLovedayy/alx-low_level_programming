#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at specified index
 * @head: pointer to head
 * @idx: specified index
 * @n: value of new node
 * Return: address of new node or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *current;
	listint_t *newNode = malloc(sizeof(listint_t));

	/*return NULL if memory allocation for new node fails*/
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	/*Insert new node at the beginning when idx is 0*/
	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	/*Traverse list to find node before targe position*/
	current = *head;
	for (i = 0; i < idx - 1; ++i)
	{
		if (current == NULL)
		{
			free(newNode);
			return (NULL);
		}
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;

	return (newNode);
}
