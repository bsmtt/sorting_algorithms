#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: an array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_index = 0;
    int temp;

    for (i = 0; i < size; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
		print_array(array, size);
    }
}
