#include "sort.h"

/**
 * shell_sort - sort the array using the Knuth interval
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t knuth_seq, i, j;
	int temp;

	knuth_seq = 1;
	while (knuth_seq < size)
		knuth_seq = (3 * knuth_seq) + 1;

	while (knuth_seq > 0)
	{
		for (i = knuth_seq; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= knuth_seq && array[j - knuth_seq] >= temp)
			{
				array[j] = array[j - knuth_seq];
				j = j - knuth_seq;
			}
			array[j] = temp;
		}
		knuth_seq = (knuth_seq - 1) / 3;
		print_array(array, size);
	}
}
