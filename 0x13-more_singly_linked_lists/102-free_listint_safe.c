#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely even if it contains a loop
 * @head: A pointer to a pointer to the first node of the linked list
 * Return: Number of nodes in the list that were freed
 */
size_t free_listint_safe(listint_t **head)
{
	size_t nodesFreed = 0; /* Counter for the number of nodes freed */
	listint_t *current = *head; /* Pointer to the current node */

	if (!head || !(*head))
		return (0); /* If the list is empty, nothing to free */

	while (current)
	{
		listint_t *nextNode = current->next; /* Pointer to next node in the list */

		if (nextNode >= current)
		{
			/**
			* If the address of the next node is greater than or equal to the
			* current node, a loop is detected. Free current node and break loop.
			*/
			free(current);
			nodesFreed++;
			break;
		}
		else
		{
			/* No loop detected, proceed to free current node and move to next one */
			free(current);
			nodesFreed++;
			current = nextNode;
		}
	}

	*head = NULL; /* Set the head pointer to NULL after freeing the list */
	return (nodesFreed); /* Return the number of nodes freed */
}
