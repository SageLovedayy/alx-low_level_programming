#include "lists.h"


/**
* print_listint - prints all elements of a listint_t list
* @h: pointer to linked list
* Return: number of nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t nodeCount = 0;
	const listint_t *current;

	current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		nodeCount++;
	}

	return (nodeCount);
}
