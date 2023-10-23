#include "lists.h"

/**
* free_listint2 - frees a linked list, setting head to NULL
* @head: pointer to pointer to first node of linked list
*/
void free_listint2(listint_t **head)
{
	listint_t *current;
	listint_t *next;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
