
#include "sort.h"

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1);
}

void quick_sort_helper(int *array, size_t low, size_t high)
{
    if (low < high)
    {
        size_t partition_index = lomuto_partition(array, low, high);
        if (partition_index > 0)
            quick_sort_helper(array, low, partition_index - 1);
        quick_sort_helper(array, partition_index + 1, high);
    }
}

size_t lomuto_partition(int *array, size_t low, size_t high)
{
    int pivot = array[high];
    size_t i = low - 1;

    size_t j;
    for (j = low; j < high; ++j)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1);  // Print array after each swap
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1);  // Print array after placing pivot

    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
