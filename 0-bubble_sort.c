#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
size_t i;
int temp, sorted;

	while (1)
	{
		sorted = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				if (i < size - 1)
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					sorted = 1;
					aux_func(array, size);

				}
			}
		}
		if (sorted == 0)
			break;
	}
}

/**
 * aux_func - function that sorts an array of integers in ascending order
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
