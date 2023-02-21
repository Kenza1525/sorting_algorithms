#include "sort.h"
#include <stdio.h>
/**
 * selection_sort -  sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array passed to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int a;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		int min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				k = j;
			}
		}
		if (min < array[i] || min > array[i])
		{
			a = array[i];
			array[i] = array[k];
			array[k] = a;
			print_array(array, size);
		}
	}
}
