#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a linked list
 * @head: pointer to head node of linked list
 * @index: desired index
 * Return: node at desired index, NULL if index is out of bounds
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	/*Loop traverses linked list till end or until desired index is reached*/
	while (head != NULL)
	{
		/*Conditional returns current node if it is the desired index*/
		if (count == index)
			return (head);
		/*Move to next node*/
		head = head->next;
		count++;
	}
	/*Return null if index is out of bounds*/
	return (NULL);
}
