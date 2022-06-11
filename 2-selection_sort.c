#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of numbers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, position, temp, x;

	for (i = 0; i < size - 1; i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[position] > array[j])
				position = j;
		}
		if (position != i)
		{
			temp = array[i];
			array[i] = array[position];
			array[position] = temp;
			for (x = 0; x <= size - 1; x++)
			{
				printf("%d", array[x]);
				if (x != size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
}
