#include "sort.h"
/**
 * selection_sort - sort the array using selection sort algorithm
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: the sorted array in ascending order using SSA
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t min_val, i, j;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_val = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_val])
				min_val = j;
			continue;
		}
		if (min_val != i)
		{
			temp = array[i];
			array[i] = array[min_val];
			array[min_val] = temp;
			print_array(array, size);
		}
		else
			print_array(array, size);
	}
}
