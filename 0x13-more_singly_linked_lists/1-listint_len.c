#include "lists.h"

/**
 * listint_len - singly linked list
 * @h: pointer to linked list
 * Return: number of elements in linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t nodeCount = 0;

	while (h != NULL)
	{
		nodeCount++;
		h = h->next;
	}

	return (nodeCount);
}
