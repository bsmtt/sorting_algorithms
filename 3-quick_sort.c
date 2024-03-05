#include "sort.h"

/**
 * swap_items - Swap two numbers in array.
 * @num1: The first integer to swap.
 * @num2: The second integer to swap.
 */
void swap_items(int *num1, int *num2)
{
int tmp;

tmp = *num1;
*num1 = *num2;
*num2 = tmp;
}

/**
 * getPivot - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int getPivot(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_items(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_items(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * get_quick_sort - implements quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void get_quick_sort(int *array, size_t size, int left, int right)
{
	int pivot_index;

	if (right - left > 0)
	{
		pivot_index = getPivot(array, size, left, right);
		get_quick_sort(array, size, left, pivot_index - 1);
		get_quick_sort(array, size, pivot_index + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the quick sort algorithm
 * @array: an array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	get_quick_sort(array, size, 0, size - 1);
}
