#include "sort.h"
#include <stdio.h>

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int a;

	for (i = 0; i < size; i++)
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
		if (min != array[i])
		{
			a = array[i];
			array[i] = array[k];
			array[k] = a;
		}
                print_array(array, size);
	}
}
