#include "sort.h"

/**
 * swap - swap the element
 *
 * @array: the pointer to the array
 * @size: the size of the array
 * @x: the first
 * @y: the last
 *
 * Return: void
 */
void swap(int *array, size_t size, int *x, int *y)
{
	int temp;

	if (*x != *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
		print_array(array, size);
	}
	else
		print_array(array, size);
}


/**
 * hoare_partition - get the index of the pivot using hoare partitioning scheme
 *
 * @array: the pointer to the array
 * @size: the size of the array
 * @low: the start index of the array
 * @high: the last index of the array
 *
 * Return: the index of the pivot
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot_val, l_ptr, r_ptr;

	pivot_val = array[high];
	l_ptr = low - 1;
	r_ptr = high + 1;

	while (1)
	{
		do
			l_ptr++;
		while (array[l_ptr] < pivot_val);

		do
			r_ptr--;
		while (array[r_ptr] > pivot_val);

		if (l_ptr >= r_ptr)
			return (r_ptr);
		swap(array, size, &array[l_ptr], &array[r_ptr]);
	}
}

/**
 * hoare_algo - sorts the array using hoare algorithm for partitioning
 *
 * @array: the ponter to the array
 * @size: the size of the array
 * @start: the start index of the array
 * @end: the last index of the array
 *
 * Return: void
 */

void hoare_algo(int *array, size_t size, int start, int end)
{
	if (start < end)
	{
		int pivot_index = hoare_partition(array, size, start, end);

		hoare_algo(array, size, start, pivot_index - 1);
		hoare_algo(array, size, pivot_index, end);
	}
}


/**
 * quick_sort_hoare - sorts the array of using hoare partitoning
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;
	hoare_algo(array, size, 0, size - 1);
}
