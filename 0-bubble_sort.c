#include "sort.h"
/**
 * bubble_sort - sort the element using Bubble sort algorithm
 *
 * @array: the pointer to the array
 * @size: the number of element in the array
 *
 * Return: the array in the ascending order
 */

void bubble_sort(int *array, size_t size)
{
	int num_temp, flag;
	size_t i, j;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				num_temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = num_temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
