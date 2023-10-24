#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at specified index of linked list
 * @head: pointer to head of linked list
 * @index: specified index
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *current, *previous;
	unsigned int i = 0;

	/*return -1 since deletion is not possible for empty list*/
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	/*Traverse list to find node before target position*/
	current = *head;
	previous = NULL;

	while (current != NULL && i < index)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);

	return (1);
}



