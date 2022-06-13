#include "sort.h"

/**
 * insertion_sort_list - function that sorts an array of integers
 * in ascending order
 * @list: Head of doble linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sw_node;
/*Define temp to traverse the list and and sw_node to insert bef or aftr*/

	if (!list)/*Input control*/
		return;

	temp = *list;/*Assign head to temp*/

	while (temp)/*Traverse till the end of the list*/
	{/*if not at the end node and next unordered > (insert)*/
		while (temp->next && (temp->n > temp->next->n))
		{
			sw_node = temp->next;/*Set new node to the unsorted node*/
			/*Keep the conection to the folowing nodes of the list*/
			temp->next = sw_node->next;
			/*Keep the conection to the previous nodes of the list*/
			sw_node->prev = temp->prev;
			if (temp->prev)/*if not at the begining*/
				/*Keep the conection from the previous nodes of the list*/
				temp->prev->next = sw_node;
			if (sw_node->next)/*If not at the end*/
				/*Keep the conection from the folowing nodes of the list*/
				sw_node->next->prev = temp;
			/*Interconnect new inserted positions*/
			temp->prev = sw_node;
			sw_node->next = temp;
			if (sw_node->prev)/*If not at the begining*/
				/*Decrement 1 position in the list*/
				temp = sw_node->prev;
			else /*set the new node as the head of the list*/
				*list = sw_node;
			print_listint(*list);
		} /*Increment 1 position in the list*/
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
