#include "sort.h"

void _swap(int *array, int i, int j, size_t size)
{
	if (array[i] != array[j])
	{
		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];
		print_array(array, size);
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
    size_t i = low;

    for (size_t j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            swap(&array[i], &array[j]);
            print_array(array, size);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    print_array(array, size);

    return i;
}

/**
 * quicksort - Recursive function to perform Quick Sort using Lomuto scheme
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

        if (pivot_idx != 0)
            quicksort(array, low, pivot_idx - 1, size);

        quicksort(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort - Wrapper function for Quick Sort using Lomuto scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quicksort(array, 0, size - 1, size);
}
