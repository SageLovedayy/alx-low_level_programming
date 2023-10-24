#include "lists.h"

/**
 * pop_listint - deletes head node of linked list
 * @head: pointer to pointer to head of linked list
 * Return: head node's data, 0 if linked list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	data = (*head)->n;

	temp = *head;
	*head = (*head)->next;

	free(temp);

	return (data);
}
