#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, x;
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
					for (x = 0; x <= size - 1; x++)
					{
						printf("%d", array[x]);

						if (x != size - 1)
						{
							printf(", ");
						}
					}
					printf("\n");
				}
			}
		}
		if (sorted == 0)
			break;
	}
}
