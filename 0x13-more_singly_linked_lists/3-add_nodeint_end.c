#include "lists.h"

/**
* add_nodeint_end - adds new node to end of listint_t list
* @head: pointer to pointer to node containing address of first node
* @n: value of new node
* Return: address of new element or NULL on failure
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL; /*since new node will be last node,*/
	/*it has to point to NULL*/

	if (*head == NULL)
		*head = newNode;

	else
	{
		listint_t *current = *head;

		while (current->next != NULL)
			current = current->next;

		current->next = newNode;
	}

	return (newNode);

}
