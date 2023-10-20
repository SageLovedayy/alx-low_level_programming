#include "lists.h"

/**
* list_len - calculates no of elements in linked list
* @h:pointer to head of list_t linkedlist
*Return: the number of elements
*/
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
