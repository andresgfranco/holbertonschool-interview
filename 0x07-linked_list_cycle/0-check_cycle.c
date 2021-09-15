#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - Checks whether a linked list have a cycle or not.
 * @list: Given linked list to check.
 *
 * Return: It returns 0 if there is no cycle, otherwise 1.
 */

int check_cycle(listint_t *list)
{
	listint_t *a, *b;

	a = b = list;

	while (a && b && a->next)
	{
		a = a->next->next;
		b = b->next;

		if (b == a)
			return (1);
	}

	return (0);
}
