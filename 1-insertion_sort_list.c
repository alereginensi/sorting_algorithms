#include "sort.h"

/**
 * insertion_sort_list - function that sorts an array of integers
 * in ascending order
 * @list: Head of doble linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sw_node;

	if (!list)
		return;

	temp = *list;

	while (temp)
	{
		while (temp->next && (temp->n > temp->next->n))
		{
			sw_node = temp->next;
			temp->next = sw_node->next;
			sw_node->prev = temp->prev;

			if (temp->prev)
				temp->prev->next = sw_node;

			if (sw_node->next)
				sw_node->next->prev = temp;

			temp->prev = sw_node;
			sw_node->next = temp;

			if (sw_node->prev)
				temp = sw_node->prev;
			else
				*list = sw_node;

			print_listint(*list);
		}
		temp = temp->next;
	}
}

/**
 * print_listint - function that prints the int values for a dllist
 * @h: Head of doble linked list
 */
void print_listint(const listint_t *h)
{
	while (h != NULL)/* Traverse to the last node */
	{
		printf("%d", h->n);
		if (h->next != NULL)
			printf(", ");
		h = h->next;
	}
	printf("\n");
}
