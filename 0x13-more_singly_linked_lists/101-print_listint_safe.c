#include "lists.h"

/**
 *print_listint_safe - function that prints a listint_t linked list.
 *@head: A pointer to the head of the list
 *Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("[%d] %d\n", head->next, head->n);
		count++;
		if (head < head->next)
			head = head->next;
		else
			exit(98);
	}
	return (count);
}
