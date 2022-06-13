#include "sort.h"

/**
 * insertion_sort_list - function that sorts an array of integers
 * in ascending order
 * @list: Head of doble linked list
 */
void insertion_sort_list(listint_t **list)
{
	int sorted = 0, last = 0;
	listint_t *temp = *list;

		if (temp == NULL)
			return;

		/* Traverse to the last to sort the value using insetion sort alg */
		while (temp != NULL)
		{
			sorted = 0;
			if (temp->next->n < temp->n)
			{
				sorted = 1;
				if (temp->prev == NULL)
				{
					temp = swap_first(temp, temp->next);
					*list = temp;
				}
				else if (temp->next->next == NULL)
				{
					temp = swap_last(temp, temp->next);
					last = 1;
				}
				else
					temp = swap_middle(temp, temp->next);
				print_listint(*list);
			}
			/* End control */
			if (last == 1 && sorted == 0)
				break;
			/* select forward or backward traverse */
			if (sorted == 0 || temp->prev == NULL)
				temp = temp->next;
			else
				temp = temp->prev;
		}
}

/**
 * swap_first - function that swaps two nodes at the head of the dllist
 * @temp: Head of doble linked list
 * @sw_node: Node to be swaped
 * Return: Node address after swap
 */
listint_t *swap_first(listint_t *temp, listint_t *sw_node)
{
	listint_t *aux_after;
	/* Reserve second position in temp */
	aux_after = sw_node->next;
    /* Make next of swap node as head and previous as NULL */
	aux_after->prev = temp;
	sw_node->next = sw_node->prev;
	temp->next = aux_after;
	temp->prev = sw_node;
	sw_node->prev = NULL;
	return (sw_node);
}

/**
 * swap_last - function that swaps two nodes at the end of the dllist
 * @temp: Head of doble linked list
 * @sw_node: Node to be swaped
 * Return: Node address after swap
 */
listint_t *swap_last(listint_t *temp, listint_t *sw_node)
{
	listint_t *aux_before;

	aux_before = temp->prev;
	/* Swap node at the end */
	sw_node->next = sw_node->prev;
	sw_node->prev = temp->prev;
	aux_before->next = sw_node;
	temp->prev = temp->next;
	temp->next = NULL;
	return (sw_node);
}

/**
 * swap_middle - function that swaps two nodes at the middle of the dllist
 * @temp: Head of doble linked list
 * @sw_node: Node to be swaped
 * Return: Node address after swap
 */
listint_t *swap_middle(listint_t *temp, listint_t *sw_node)
{
	listint_t *aux_after, *aux_before;
	/* Preserve previous and folowing positions */
	aux_before = temp->prev;
	aux_after = sw_node->next;
    /* Swap node middle */
	sw_node->next = sw_node->prev;
	sw_node->prev = aux_before;
	temp->prev = temp->next;
	temp->next = aux_after;
	aux_before->next = sw_node;
	aux_after->prev = temp;
	return (sw_node);
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
