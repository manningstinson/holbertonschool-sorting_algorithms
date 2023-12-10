#include "sort.h"

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

size_t lomuto_partition(int *array, size_t low, size_t high) {
    size_t i;
    size_t q = low - 1;
    int pivot = array[high];

    for (i = low; i < high; ++i) {
        if (array[i] <= pivot) {
            ++q;
            swap(&array[q], &array[i]);
        }
    }

    swap(&array[q + 1], &array[high]);
    return q + 1;
}

void quick_sort_helper(int *array, size_t low, size_t high) {
    size_t pi;

    if (low < high) {
        pi = lomuto_partition(array, low, high);
        quick_sort_helper(array, low, pi);       // Adjusted recursive call
        quick_sort_helper(array, pi + 1, high);
    }
}

void quick_sort(int *array, size_t size) {
    if (size < 2) {
        return;
    }
    quick_sort_helper(array, 0, size - 1);
}
