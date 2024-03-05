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
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: an array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, min_index;

if (!array || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
min_index = i;
for (j = i + 1; j < size; j++)
min_index = (array[j] < array[min_index]) ? j : min_index;

if ((array + i) != array + min_index)
{
swap_items(array + i, array + min_index);
print_array(array, size);
}
}
}
