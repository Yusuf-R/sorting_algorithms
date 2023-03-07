#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * max_element - finds the maximum number in the array
 * @x: pointer to the array
 * @n: the size of the array
 *
 * Return: the maximum number
 */

int max_element(int *x, size_t n)
{
	size_t i;
	int max;

	i = 0, max = 0;
	while (i < n)
	{
		if (x[i] < 0)
			return (-1);
		if (x[i] > max)
			max = x[i];
		i++;
	}
	return (max);
}
/**
 * counting_sort - sort the array using counting sort algorithm
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int k, i;
	int *aux_array, *sort_array;

	if (!array || !size || size < 2)
		return;
	k = max_element(array, size);
	if (k == -1)
		return;

	aux_array = malloc(sizeof(int) * (k + 1));
	if (!aux_array)
		return;
	for (i = 0; i <= k; i++)
		aux_array[i] = 0;
	for (i = 0; (size_t)i < size; i++)
		aux_array[array[i]]++;
	for (i = 1; i <= k; i++)
		aux_array[i] = aux_array[i] + aux_array[i - 1];
	print_array(aux_array, (size_t) k + 1);

	sort_array = malloc(sizeof(int) * size);
	if (!sort_array)
	{
		free(aux_array);
		aux_array = NULL;
		return;
	}
	for (i = size - 1; i >= 0; i--)
		sort_array[--aux_array[array[i]]] = array[i];
	for (i = 0; (size_t)i < size; i++)
		array[i] = sort_array[i];
	free(sort_array);
	free(aux_array);
	sort_array = NULL;
	aux_array = NULL;
}
