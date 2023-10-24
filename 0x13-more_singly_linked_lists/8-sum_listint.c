#include "lists.h"

/**
 * sum_listint - sums all data of a linked list
 * @head: Head of linked list
 * Return: sum of data of linked list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	listint_t *current = head;

	if (current == NULL)
		return (0);

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}

