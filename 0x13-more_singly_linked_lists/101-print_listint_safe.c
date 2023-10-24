#include "lists.h"

/**
 * print_listint_safe - prints a linked list
 * @head: head of linked list
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	/* USING FLOYD'S CYCLE FINDING ALGORITHM*/

	size_t pichu = 0;
	const listint_t *aux_node = head;

	if (!head)
		exit(98);

	while (aux_node)
	{
		printf("[%p] %i\n", (void *)aux_node, aux_node->n);
		aux_node = aux_node->next;
		pichu++;
	}
	return (pichu);
}
