#include "sort.h"

/* Function Prototypes */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size);
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size);
void swap(int *a, int *b);

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
    print_array(array, size);
}

void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t partition_index = lomuto_partition(array, low, high, size);
        if (partition_index > 0)
            quick_sort_helper(array, low, partition_index - 1, size);
        quick_sort_helper(array, partition_index + 1, high, size);
    }
}

size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; ++j)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(const int *array, size_t size)
{
    size_t i = 0;

    while (i < size)
    {
        if (i > 0)
            write_char(',');
        write_num(array[i]);
        ++i;
    }
    write_char('\n');
}

