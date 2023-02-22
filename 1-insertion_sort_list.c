#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: double pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;

	temp = NULL;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	if ((*list)->next == NULL)
		return;
	temp = (*list)->next;

	while (temp != NULL)
	{
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->prev->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		temp = temp->next;
	}
}
