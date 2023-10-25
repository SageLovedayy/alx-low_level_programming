#include "lists.h"

/**
 * print_listint_safe - prints a linked list
 * @head: head of linked list
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	/* USING FLOYD'S CYCLE FINDING ALGORITHM*/

	const listint_t *slow, *fast, *temp;
	size_t nodeCount = 0;
	int loopDetected = 0;
	int loopNodeCount = 0;

	slow = fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		nodeCount++;

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loopDetected = 1;
			break;
		}
	}

	/*Detect loop and print associated nodes*/
	if (loopDetected)
	{
		temp = slow;

		do {
			printf("[%p] %d\n", (void *)temp, temp->n);
			temp = temp->next;
			loopNodeCount++;
		} while (temp != slow);

		printf("-> [%p] %d\n", (void *)temp, temp->n);
		nodeCount += loopNodeCount;
		exit(98);
	}
	return (nodeCount);
}
