#include "sort.h"

/**
 * array_dup - copy array A to B
 *
 * @x: first array
 * @y: second array
 * @n: size of array
 *
 * Return: void
 *
 */

void array_dup(int *x, int *y, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		y[i] = x[i];
}

/**
 * merge - merges the sorted array
 *
 * @array: pointer to the array
 * @l: start index
 * @m: the mid point
 * @r: the last index
 * @aux: pointer to the array
 *
 * Return: void
 */

void merge(int *array, size_t l, size_t m, size_t r, int *aux)
{
	size_t i, j, k;

	i = l;
	j = m;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + m, r - m);

	for (k = l; k < r; k++)
	{
		if (i < m && (j >= r || array[i] <= array[j]))
		{
			aux[k] = array[i];
			i++;
		}
		else
		{
			aux[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(aux + l, r - l);
}

/**
 * top_down_split_recursion - splits the array into two halves
 *
 * @aux: pointer to the auxilliary array
 * @l_idx: start index
 * @r_idx: last index
 * @array: pointer to the array
 *
 * Return: void
 */

void top_down_split_recursion(int *aux, size_t l_idx, size_t r_idx, int *array)
{
	size_t mid_point;

	if (r_idx - l_idx < 2)
		return;

	mid_point = (r_idx + l_idx) / 2;

	top_down_split_recursion(array, l_idx, mid_point, aux);
	top_down_split_recursion(array, mid_point, r_idx, aux);

	merge(aux, l_idx, mid_point, r_idx, array);

}

/**
 * merge_sort - sort the array using merge sort
 *
 * @array: pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t left_idx;
	int *aux_arr;

	left_idx = 0;

	if (!array || size < 2)
		return;

	aux_arr = malloc(sizeof(int) * size);
	if (!aux_arr)
		return;

	array_dup(array, aux_arr, size);

	top_down_split_recursion(array, left_idx, size, aux_arr);
	free(aux_arr);
}
