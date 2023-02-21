#include "sort.h"
#include <stdio.h>


void bubble_sort(int *array, size_t size)
{
	size_t i, j, a;

	if (size == 0)
        {
                return;
        }

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[i] > array[i+1])
		       	{
				a = array[i];
				array[i] = array[i+1];
				array[i+1] = a;
				print_array(array, size);
			}
		}
	}
}

/*
int* bubble(int *array, size_t size)
{
        size_t i, a;

        if (size == 0)
        {
                return;
        }

        if (array[i] > array[i+1])
	{
		a = array[i];
		array[i] = array[i+1];
		array[i+1] = a;
		print_array(array, size);
        }
	return bubble(array, size - 1);
}


void bubble_sort(int *array, size_t size)
{
	int* a = bubble(array, size);
	print_array(a);
}
*/
