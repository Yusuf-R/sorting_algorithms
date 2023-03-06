#include "sort.h"

/**
 * node_swap - swap the nodes of the DLL
 *
 * @x: first node
 * @y: second node
 *
 * Return: void
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
 * trav_bkwd - start from the end and sort backwards
 *
 * @fwd: pointer at the end of fwd movement
 * @bkwd: pointer starting from the end of fwd to move bkwds
 * @list: the pointer to the end of the node
 *
 * Return: the pointer to the end of bkwd traversing
 */

listint_t *trav_bkwd(listint_t *fwd, listint_t *bkwd, listint_t *list)
{
	while (bkwd && bkwd->prev)
	{
		if (bkwd->n < bkwd->prev->n)
		{
			node_swap(bkwd->prev, bkwd);
			if (bkwd->prev == NULL)
				list = bkwd;
			print_list(list);
		}
		else
			bkwd = bkwd->prev;
		if (bkwd->prev == NULL)
			fwd = bkwd;
	}
	return (fwd);
}
/**
 * cocktail_sort_list - sort the DLL using CS-sort
 *
 * @list: a double pointer the node
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *fwd_trav, *bk_trav, *len;
	int swap, i, j;

	if (!list || !*list)
		return;

	len = *list;
	for (i = 0; len; i++)
		len = len->next;

	if (i < 2)
		return;

	fwd_trav = *list;
	swap = 1;
	j = 0;

	while (j < i)
	{
		swap = 0;
		while (fwd_trav && fwd_trav->next)
		{
			if (fwd_trav->n > fwd_trav->next->n)
			{
				node_swap(fwd_trav, fwd_trav->next);
				swap++;
				if (fwd_trav->prev->prev == NULL)
					*list = fwd_trav->prev;
				print_list(*list);
			}
			else
				fwd_trav = fwd_trav->next;
			if (fwd_trav->next == NULL)
				bk_trav = fwd_trav;
		}
		fwd_trav = trav_bkwd(fwd_trav, bk_trav, *list);
		*list = fwd_trav;
		j++;
	}
}

