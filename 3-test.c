#include "sort.h"
#include <stddef.h>

/**
 * swap - swaps values of two elements
 * @a: pointer to the first element
 * @b: pointer to the second element
 */

void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * lomuto_partition - divise the array into two subarrays
 * @array: the array to be subdivided
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: an index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}
	}

	if (array[i] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * recursive_sort - partitions an array into two parts
 * @array: array to be sorted
 * @low: index of the greater element
 * @high: index of the last element
 * @size: size of the array
 */

void recursive_sort(int array[], int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		recursive_sort(array, low, p - 1, size);
		recursive_sort(array, p + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_sort(array, 0, size - 1, size);
}
