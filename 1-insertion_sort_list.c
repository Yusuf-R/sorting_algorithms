#include "sort.h"

/**
 * node_swap - this function swaps two nodes
 *
 * @x: pointer to the first node
 * @y: pointer to the second node
 *
 * Retunrn: void
 */

void node_swap(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}


/**
 * insertion_sort_list - this function impplements ISA
 * on a double linked list
 *
 * @list: double pointer to the array
 *
 * Retunrn: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *trav,  *temp;

	if (!*list || !list || !(*list)->next)
		return;
	trav = (*list)->next;
	while (trav)
	{
		temp = trav;
		trav = trav->next;
		while (temp && temp->prev)
		{
			if (temp->prev->n  > temp->n)
			{
				node_swap(temp->prev, temp);
				if (!temp->prev)
					*list = temp;
				print_list((const listint_t *) *list);
			}
			else
				temp = temp->prev;
		}
	}
}
