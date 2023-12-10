#include "sort.h"

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1);
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
    int pivot = array[high];
    size_t i = low;
    size_t j;

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
    int temp = *a;
    *a = *b;
    *b = temp;
}
