#include "sort.h"

/**
 * _swap - change two positions
 * @array: variable int
 * @i: variable int
 * @j: variable int
 * @size: variable size
 */
void _swap(int *array, int i, int j)
{
    /* Check if values are different to avoid unnecessary operations */
    if (array[i] != array[j])
    {
        /* XOR operation to swap element values */
        array[i] ^= array[j];
        array[j] ^= array[i];
        array[i] ^= array[j];
    }
}


/**
 * partition - function sort a partition
 * @array: variable int
 * @start: variable int
 * @end: variable int
 * @size: variable size
 * Return: int
 */

int partition(int *array, int start, int end, size_t size)
{
	int i = start, j, pivot = array[end];

	for (j = start; j <= end; j++)
	{
		if (array[j] < pivot)
		{
			_swap(array, i, j, size);
			i++;
		}
	}
	_swap(array, i, end, size);
	return (i);
}

/**
 * quicksort - function sorts an array of integers in ascending
 * @array: variable int
 * @start: variable int
 * @end: variable int
 * @size: variable size
 */

void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
	{
		return;
	}
	pivot = partition(array, start, end, size);
	quicksort(array, start, pivot - 1, size);
	quicksort(array, pivot + 1, end, size);
}

/**
 * quick_sort - function sorts an array of integers in ascending
 * @array: variable int
 * @size: variable size
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
