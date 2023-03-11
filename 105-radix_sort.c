#include "sort.h"

/**
 * radix_sort -  sort the array using LSD for radix sort algorithm
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: void
 */


void radix_sort(int *array, size_t size)
{
	int max_num, place_val;

	if (!array || size < 2)
		return;

	max_num = max_element(array, size);

	for (place_val = 1; max_num / place_val > 0; place_val *= 10)
	{
		counting_sort_lsd(array, size, place_val);
		print_array(array, size);
	}
}

/**
 * max_element - find the maximum element in the array
 *
 * @array: the pointer to the array
 * @size: the size of the array
 *
 * Return: the maximum element in the array
 */

int max_element(int *array, size_t size)
{
	int max;
	size_t i;

	max = 0;
	i = 0;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * counting_sort_lsd -  sort the array using LSD for counting sort algorithm
 *
 * @array: the pointer to the array
 * @size: the size of the array
 * @place_val: the place value of the array element.
 *
 * Return: void
 */

void counting_sort_lsd(int *array, size_t size, int place_val)
{
	int i, j, k;
	int bucket[10] = {0};
	int *temp;

	for (i = 0; (size_t)i < size; i++)
		bucket[(array[i] / place_val) % 10]++;
	for (i = 1; i < 10; i++)
		bucket[i] += bucket[i - 1];

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	for (i = size - 1; i >= 0; i--)
	{
		j = bucket[(array[i] / place_val) % 10] - 1;
		k = array[i];
		temp[j] = k;
		bucket[(array[i] / place_val) % 10]--;
	}
	for (i = 0; (size_t)i < size; i++)
	{
		array[i] = temp[i];
	}
	free(temp);
}
