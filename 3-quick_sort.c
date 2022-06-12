#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of arrays
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	aux_sort(array, 0, size - 1, size);
}

/**
 * aux_sort - sorts an array of integers using Quick sort algorithm
 * and Lomuto partition scheme
 * @array: array of numbers
 * @last: size -1 of the array
 * @size: size of the array
 * @first: 0
 */
void aux_sort(int *array, size_t first, size_t last, size_t size)
{
	size_t i, j, pivot, temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (array[i] <= array[pivot] && i < last)
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		aux_func(array, size);
		aux_sort(array, first, j - 1, size);
		aux_sort(array, j + 1, last, size);
	}
}

/**
 * aux_func - function that prints an array of integers
 * @array: array
 * @size: size
 */
void aux_func(int *array, size_t size)
{
	size_t x;

	for (x = 0; x <= size - 1; x++)
	{
		printf("%d", array[x]);
		if (x != size - 1)
			printf(", ");
	}
	printf("\n");
}
