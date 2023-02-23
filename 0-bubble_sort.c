#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble sort
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int a;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
				print_array(array, size);
			}
		}
	}
}

