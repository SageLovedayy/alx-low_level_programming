#include "lists.h"

/**
 * listint_len - singly linked list
 * @h: pointer to linked list
 * Return: number of elements in linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t count;

	const listint_t *current;

	current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
