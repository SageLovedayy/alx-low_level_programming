#include "lists.h"

/**
 * print_listint_safe - prints a linked list safely even if it contains a loop
 * @head: head of the linked list
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodeCount = 0;

	slow = fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		nodeCount++;

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			printf("-> [%p] %d\n", (void *)fast->next, fast->next->n);
			printf("Loop starts at [%p]\n", (void *)slow);
			exit(98);
		}
	}

	return (nodeCount);
}
