#include "lists.h"

/**
 * free_listint_safe - frees linked lists with a loop
 * @h: pointer to pointer to first node of linked list
 * Return: size of list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t nodeCount = 0;
	listint_t *freedNodes[100];
	size_t i;

	slow = fast = *h;
	/* Detect loop */
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		/*Free nodes while detecting loop*/
		if (slow == fast)
		{
			slow = *h;
			while (slow != fast)
			{
				temp = slow;
				freedNodes[nodeCount++] = temp;
				slow = slow->next;
				free(temp);
			}
			/* move fast pointer one step ahead */
			fast = fast->next;
			/*Free the loop node */
			freedNodes[nodeCount++] = slow;
			free(slow);
			/*Set head to NULL to indicate the list is freed */
			*h = NULL;

			for (i = 0; i < nodeCount; ++i)
			{
				printf("[%p] %d\n", (void *)freedNodes[i], freedNodes[i]->n);
			}
			return (nodeCount);
		}
	}
	/* No loop, free the entire list normally */
	while (*h != NULL)
	{
		temp = *h;
		*h = (*h)->next;
		freedNodes[nodeCount++] = temp;
		free(temp);
	}
	for (i = 0; i < nodeCount; ++i)
	{
		printf("[%p] %d\n", (void *)freedNodes[i], freedNodes[i]->n);
	}
	return (nodeCount);
}
