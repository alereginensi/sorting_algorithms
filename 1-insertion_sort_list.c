#include "sort.h"

/**
 * insertion_sort_list - function that sorts an array of integers in ascending order
 * @list: Head of doble linked list
 */
void insertion_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *temp = *list;

		if (temp == NULL)
			return;

		/* Traverse to the last to sort the value using insetion sort alg */
		while (temp != NULL)
		{
			printf("temp->next->n = %d - temp->n = %d\n", temp->next->n, temp->n);
			if (temp->next->n < temp->n)
			{
				sorted = 1;
				if (temp->prev == NULL)
					(*list) = swap_first((*list), temp->next);
				else if (temp->next == NULL)
					temp = swap_last(temp, temp->next);
				else
					temp = swap_middle(temp, temp->next);
				print_listint(*list);
			}
			/* select forward or backward traverse */
			if (sorted == 0)
			{
				printf("pica");
				temp = temp->next;
			}
			else
				temp = temp->prev;
		}
}

/**
 * insertion_sort_list - function that sorts an array of integers in ascending order
 * @list: Head of doble linked list
 * Return:
 */
listint_t *swap_first(listint_t *head, listint_t *sw_node)
{
	listint_t *aux;
	/* Reserve second position in temp */
	aux = sw_node->next;

	printf("Swap_first");
    /* Make next of swap node as head and previous as NULL */
	sw_node->next = head;
	sw_node->prev = NULL;

    /* Change prev of head node to new node */
	if (head != NULL)
	{
		head->prev = sw_node;
		head->next = aux;
	}

    /* Move the head to point to the new node */
	head = sw_node;

	return (sw_node);
}

listint_t *swap_last(listint_t *temp, listint_t *sw_node)
{
	printf("Swap_last");
    /* Swap node at the end */
    sw_node->prev = temp->prev;
	sw_node->next = temp;
	temp->prev = sw_node;
	temp->next = NULL;
	return (sw_node);
}

listint_t *swap_middle(listint_t *temp, listint_t *sw_node)
{
	listint_t *aux_after, *aux_before;
	/* Preserve previous and folowing positions */
	aux_before = temp->prev;
	aux_after = sw_node->next;

	printf("Swap_middle");
    /* Swap node middle */
	sw_node->next = sw_node->prev;
	sw_node->prev = aux_before;
	temp->prev = temp->next;
	temp->next = aux_after;
	aux_before->next = sw_node;
	aux_after->prev = temp;
	return (sw_node);
}

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
