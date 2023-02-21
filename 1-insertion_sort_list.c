#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm.
 * @list: double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;
		while (prev_node != NULL && prev_node->n > current->n)
		{
			prev_node->next = next_node;
			if (next_node != NULL)
				next_node->prev = prev_node;
			current->prev = prev_node->prev;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			prev_node->prev = current;
			current->next = prev_node;
			if (prev_node == *list)
				*list = current;
			prev_node = current->prev;
			print_list(*list);
		}
		current = next_node;
	}
}

