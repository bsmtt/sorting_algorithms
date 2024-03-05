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
int getPivot(int arr[], size_t low, size_t high, size_t size)
{
size_t above, below = low;

for (above = low; above <= high; above++)
{
if (arr[above] < arr[high])
{
if (arr[above] < arr[below])
swap_items(arr + above, arr + above);
print_array(arr, size);
}
below++;
}
swap_items(arr + below, arr + high);
return (below);
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
