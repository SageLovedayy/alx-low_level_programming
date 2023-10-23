#include "lists.h"

/**
* free_listint - frees a linked list
* @head: first node of linked list
*/
void free_listint(listint_t *head)
{
	listint_t *current; /*declare two nodes, current and next  nodes*/
	listint_t *next;

	current = head; /*start traversing from head of linked list*/

	while (current != NULL)
	{
		next = current->next; /*save next pointer before freeing*/
		free(current); /*free current node*/
		current = next; /*move to next node*/
	}
}
