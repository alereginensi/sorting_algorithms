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
 * @high: size -1 of the array
 * @size: size of the array
 * @low: 0
 */
void aux_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now at right place */
		size_t pi = partition(array, low, high, size);

		/* Separately sort elements before */
		/* partition and after partition */
		aux_sort(array, low, pi - 1, size);
		aux_sort(array, pi + 1, high, size);
	}
}

/**
 * partition - function that partitions the array in two parts
 * @array: addres forthe given array
 * @low: begining of sub array index
 * @high: end of subarray index
 * @size: size of the given array
 * Return: index position for the new pivot between two sub arrays
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];/* pivot */
	int i = (low - 1), j = 0;/* Index of smaller element */

	for (j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than or equal to pivot */
		if (array[j] <= pivot)
		{
			i++;/* increment index of smaller element */
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				aux_func(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		aux_func(array, size);
	return (i + 1);
}

/**
 * swap - function that swaps two values in array of integers
 * @a: a element to be swaped
 * @b: b element to be swaped
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
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
