#include "sort.h"

/**
 * listint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to the head of the list
 * Return: the number of elements in a linked dlistint_t list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * main_cocktail - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: double linked list
 * Return: void
 */

void main_cocktail(listint_t **list)
{
	listint_t *current = NULL, *new = *list, *temp = NULL;
	size_t length = listint_len(*list), i = 0;

	while (i <= length)
	{
		for (current = new->next; current->next != NULL; current = current->next)
		{
			if (current->prev->n > current->n)
			{
				temp = current->prev, current->prev = temp->prev;
				if (current->next != NULL)
					current->next->prev = temp;
				temp->next = current->next, current->next = temp;
				if (temp->prev != NULL)
					temp->prev->next = current, temp->prev = current;
				if (!current->prev)
					*list = current;
				print_list(*list), current = current->next;
			}
			i++;
		}
		for (new = current; new->prev != NULL;)
		{
			if (new->prev->n > new->n)
			{
				if (new->prev->prev != NULL)
					new->prev->prev->next = new;
				else
					*list = new;
				if (new->next != NULL)
					new->next->prev = new->prev;
				temp = new->prev->prev, new->prev->next = new->next;
				new->prev->prev = new, new->next = new->prev;
				new->prev = temp, print_list(*list);
			}
			else
				new = new->prev;
		}
	}
}

/**
 * cocktail_sort_list - proves if list is NULL or not, call to main_cocktail;
 * @list: double linked list
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	main_cocktail(&(*list));
}
