#include "sort.h"
/**
 * shell_sort - using knuth interval to sort the array
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */


void shell_sort(int *array, size_t size)
{

	size_t knuth_seq, i,  gap;
	int j, flag, store;

	if (!array || !size || size < 2)
		return;

	knuth_seq = 1;

	while (knuth_seq < size)
		knuth_seq = (3 * knuth_seq) + 1;

	for (gap = knuth_seq; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			flag = 0;
			for (j = i - gap; j >= 0; j = j - gap)
			{
				if (array[j + gap] > array[j])
					break;
				store = array[j + gap];
				array[j + gap] = array[j];
				array[j] = store;
				flag = 1;
			}
		}
		if (flag == 1)
			print_array(array, size);
	}
}
