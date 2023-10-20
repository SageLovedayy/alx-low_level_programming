#include "lists.h"


/**
 * add_node_end - adds node to end of list
 * @head: pointer to pointer to head of linked list
 * @str: string
 * Return: New node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;
	char duplicate;
	int len;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	duplicate= strdup(str);

	if (str == NULL)
	{
		free(new_node);
		return (NULL);
	}


	for (len = 0; str[len];)
		len++;

	new_node->str = duplicate;
	new_node->len = len;
	new_node->next = NULL;


	if (*head == NULL)
		*head = new_node;

	else
	{
		current = *head;

		while (current->next != NULL)
			current = current->next;

		current->next = new_node;
	}

	return (*head);
}
