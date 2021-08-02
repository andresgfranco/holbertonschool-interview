#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *temp = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

    if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || temp->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while(temp->next != NULL && temp->next->n <= number)
			temp = temp->next;
		if (temp->next != NULL)
			new_node->next = temp->next;
		temp->next = new_node;
	}
	return new_node;
}
