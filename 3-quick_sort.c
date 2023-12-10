#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    if (a != b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element after partition
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot_idx = lomuto_partition(array, low, high, size);

        quicksort(array, low, pivot_idx - 1, size);
        quicksort(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort - Wrapper function for Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quicksort(array, 0, size - 1, size);
}
