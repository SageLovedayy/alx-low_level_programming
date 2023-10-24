#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to pointer to first node
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	/*ITERATIVE REVERSAL TECHNIQUE*/
	listint_t *nextNode;
	listint_t *prev = NULL;

	while (*head != NULL)
	{
		nextNode = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = nextNode;
	}

	*head = prev; /*Update pointer to point to new first node*/

	return (*head);
}
