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
 * getPivot - function that sorts an array of integers
 * in ascending order using the quick sort algorithm
 * @arr: an array of integers
 * @low: start index of partition
 * @high: last index of partition
 * @size: size of array
 *Return: return pivot index
*/
int getPivot(int *array, size_t left, size_t right, size_t size)
{
int *pivot;
size_t above, below;

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
 * get_quick_sort - sort partition
 * @array: an array of integers
 * @low: start index of partition
 * @high: last index of partition
 * @size: size of array
 */
void get_quick_sort(int *array, size_t low, size_t high, size_t size)
{
size_t pivot_index;

if (low < high)
{
pivot_index = getPivot(array, low, high, size);

get_quick_sort(array, low, pivot_index - 1, size);
get_quick_sort(array, pivot_index + 1, high, size);
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
get_quick_sort(array, 0, size - 1, size);
}
