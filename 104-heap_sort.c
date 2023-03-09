#include "sort.h"

/**
 * swap - swaps two item
 *
 * @array: pointer to the array
 * @temp_size: storing size permanently
 * @a: array to be sorted
 * @b: size of the array
 *
 * Return: void
 */

void swap(int *array, size_t temp_size, int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, temp_size);
}

/**
 * max_heapify - heapify the array by swapping the root with the last child
 *
 * @array: array to be heapify
 * @size: size of the array
 * @i: index of the root
 * @temp_size: storing temp size
 *
 * Return: void
 */

void max_heapify(int *array, size_t size, size_t i, size_t temp_size)
{
	size_t left_child = (2 * i) + 1;
	size_t right_child = (2 * i) + 2;
	size_t largest = i;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != i)
	{
		swap(array, temp_size, &array[i], &array[largest]);
		max_heapify(array, size, largest, temp_size);
	}
}

/**
 * heap_sort - sort the array using heap sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;
	size_t temp_size;

	if (!array || size < 2)
		return;

	temp_size = size;
	for (i = (size - 1) / 2; i >= 0; i--)
		max_heapify(array, size, (size_t)i, temp_size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(array, temp_size, &array[0], &array[i]);
		max_heapify(array, (size_t)i, 0, temp_size);
	}
}
