#include "sort.h"
/**
 * insertion_sort_list - insertion sort doubly linked list
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL;

	if (list == NULL)
		return;
	tmp = (*list)->next;
	while (tmp != NULL)
	{
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		tmp = tmp->next;
	}
}
