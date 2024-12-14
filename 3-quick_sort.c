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
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot;
    size_t i, j;

    pivot = array[high]; /* Pivot is always the last element */
    i = low; /* Tracks the position for smaller elements */

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size); /* Print array after each swap */
            }
            i++;
        }
    }

    if (array[i] != array[high])
    {
        swap(&array[i], &array[high]);
        print_array(array, size); /* Print array after final swap */
    }

    return (i);
}

/**
 * quick_sort_recursion - Recursively sorts an array using Quick sort
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
    size_t pivot_idx;

    if (low < high)
    {
        pivot_idx = lomuto_partition(array, low, high, size);

        if (pivot_idx > 0)
            quick_sort_recursion(array, low, pivot_idx - 1, size);

        quick_sort_recursion(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Description: This function implements the Quick sort algorithm
 * using the Lomuto partition scheme. The array is printed after
 * each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursion(array, 0, size - 1, size);
}
