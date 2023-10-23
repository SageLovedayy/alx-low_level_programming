#include "lists.h"


/**
* print_listint - prints all elements of a listint_t list
* @h: pointer to linked list
* Return: number of nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t nodeCount;

	nodeCount = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodeCount++;
	}

	return (nodeCount);
}
