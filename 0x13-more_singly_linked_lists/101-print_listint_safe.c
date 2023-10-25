#include "lists.h"

/**
 * caculate_loop_length - Calculates the length of a looped linked list.
 * @head: Pointer to the head of the linked list.
 * Return: Number of unique nodes in the loop, 0 if list is not looped.
 */
size_t caculate_loop_length(const listint_t *head)
{
	const listint_t *slow_ptr, *fast_ptr;
	size_t nodes_count = 1;

	/* Check for empty list or list with only one node */
	if (head == NULL || head->next == NULL)
		return 0;

	/* Initialize slow and fast pointers */
	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	/* Detect loop using Floyd's cycle-finding algorithm */
	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			/* Loop detected, calculate the number of nodes in the loop */
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				nodes_count++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

			/* Move slow pointer until it reaches the start of the loop */
			slow_ptr = slow_ptr->next;

			/* Count nodes in the loop */
			while (slow_ptr != fast_ptr)
			{
				nodes_count++;
				slow_ptr = slow_ptr->next;
			}

			return nodes_count;
		}

		/* Move slow pointer one step and fast pointer two steps */
		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}

	/* No loop detected */
	return 0;
}

/**
 * print_listint_safe - Safely prints a linked list, detecting loops.
 * @head: Pointer to the head of the linked list.
 * Return: Number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes_count, index = 0;

	/* Calculate the number of nodes in the looped list */
	nodes_count = caculate_loop_length(head);

	/* Loop detected, print nodes in the loop */
	if (nodes_count != 0)
	{
		for (index = 0; index < nodes_count; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	/* No loop detected, print all nodes in the list */
	else
	{
		for (; head != NULL; nodes_count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	return nodes_count;
}
