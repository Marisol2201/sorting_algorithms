#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (list == NULL || (*list) == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			if (current->next != NULL)
				current->next->prev = temp;
			temp->next = current->next;
			current->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = current;
			temp->prev = current;
			if (!current->prev)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
