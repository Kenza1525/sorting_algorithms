#include "sort.h"
/**
 * partition - partition function
 * @array: array to be sorted
 * @low: lowest element of the arr
 * @high: highest element of the arr
 * @size: size of the arr
 * Return: index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - lomuto partition
 * @array: array
 * @low: first element
 * @high: last element
 * @size: the size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int parti;

	if (low < high)
	{
		parti = partition(array, low, high, size);

		lomuto_sort(array, low, parti - 1, size);
		lomuto_sort(array, parti + 1, high, size);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
