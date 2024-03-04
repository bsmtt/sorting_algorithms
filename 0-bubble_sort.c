#include "sort.h"

/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, key;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (key = 0; key < size - 1; key++)
		{
			if (array[key] > array[key + 1])
			{
				tmp = array[key];
				array[key] = array[key + 1];
				array[key + 1] = tmp;
				print_array(array, size);
			}

		}
	}
}
