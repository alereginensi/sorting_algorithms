#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/** Aux functions **/
void aux_func(int *array, size_t size);
listint_t *swap_first(listint_t **head, listint_t *sw_node);
listint_t *swap_last(listint_t *temp, listint_t *sw_node);
listint_t *swap_middle(listint_t *temp, listint_t *sw_node);
void print_listint(const listint_t *h);
void aux_sort(int *array, size_t first, size_t last, size_t size);

#endif
