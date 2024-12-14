#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                 using the Selection sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function finds the smallest element in the unsorted
 * portion of the array and swaps it with the first unsorted element.
 * It prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        /* Find the index of the minimum value in the unsorted portion */
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        /* Swap the current element with the minimum element */
        if (min_idx != i)
        {
            swap(&array[i], &array[min_idx]);
            print_array(array, size); /* Print the array after each swap */
        }
    }
}
