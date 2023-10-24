#include "lists.h"

/**
* add_nodeint - adds new node at beginning of linked list
* @head: node to first member of list
* @n: int value to be stored in new note
* Return: new node
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;

	if (n == NULL)
		return (NULL);

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);


	newNode->n = n;

	if (newNode->n == NULL)
	{
		free(newNode);
		return (NULL);
	}

	newNode->next = *head;
	*head = newNode;

	return (newNode);
}
