#include "sort.h"
#include <stddef.h>

/**
 * swap - swaps values of two elements
 * a: pointer to the first element
 * b: pointer to the second element
 */

void swap(int *a, int *b)
{
        int c;
        c = *a;
        *a = *b;
        *b = c;
}

/**
 * partition - divise the array into two subarrays
 * @array: the array to be subdivided
 * @low: first index
 * @high: last index
 * Return: an index
 */

int partition(int array[], int low, int high)
{
	int pivot;
	int i, j;

	if (low < high)
	{
		pivot = array[high];
		i = low - 1;

		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				swap(&array[j], &array[i]);
				print_array(array, high + 1);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	return(i + 1);
}

/** quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int pi = partition(array, 0, size - 1);

	quick_sort(array, pi - 1);
	quick_sort(array, size - 1);	
}
