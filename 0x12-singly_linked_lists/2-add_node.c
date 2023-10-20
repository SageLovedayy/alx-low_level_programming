#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: Length of string
 */
int _strlen(char *s)
{
	int a = 0;

	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}

/**
* add_node- Creates a new node with given string to linked list
* @head: pointer to pointer to head of linked list
* @str: pointer to string to be duplicated
* Return: address of new node on success NULL on failure
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str); /*duplicate input string*/
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = _strlen(new_node->str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
