#include "sort.h"
#include <stdio.h>

void print_array(int *array, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    print_array(array, size); /* Print array before sorting */
    quick_sort_helper(array, 0, size - 1);
    print_array(array, size); /* Print array after sorting */
}

void quick_sort_helper(int *array, size_t low, size_t high)
{
    size_t partition_index;

    if (low < high)
    {
        partition_index = lomuto_partition(array, low, high);
        if (partition_index != 0) /* Check if partition_index is not zero */
            quick_sort_helper(array, low, partition_index - 1);
        quick_sort_helper(array, partition_index + 1, high);
    }
}

size_t lomuto_partition(int *array, size_t low, size_t high)
{
    int pivot;
    size_t i, j;

    pivot = array[high];
    i = low;

    for (j = low; j < high; ++j)
    {
        if (array[j] <= pivot) /* Include equal to pivot elements */
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    return i;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
