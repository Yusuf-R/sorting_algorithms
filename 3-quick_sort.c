#include "sort.h"
#include <stddef.h>

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
		print_array((const int *)array, size);
	}
}

/**
 * partition - get the index for the pivot
 *
 * @array: the pointer to the array
 * @size: the size of the array
 * @low: the start index of the array
 * @high: the last index of the array
 *
 * Return: the index of the pivot
 */
size_t partition(int *array, size_t size, int low, int high)
{
	int pivot_val, i, j;

	pivot_val = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_val)
		{
			swap(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * lamuto_algo - sorts the array using lamuto algorithm
 *
 * @array: the ponter to the array
 * @size: the size of the array
 * @start: the start index of the array
 * @end: the last index of the array
 *
 * Return: void
 */

void lamuto_algo(int *array, size_t size, int start, int end)
{
	size_t pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, size, start, end);
		lamuto_algo(array, size, start, pivot_index - 1);
		lamuto_algo(array, size, pivot_index + 1, end);
	}
	else 
		return;	
}


/**
 * quick_sort - sorts the array of intergers in ascending order
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;
	lamuto_algo(array, size, 0, size - 1);
}
