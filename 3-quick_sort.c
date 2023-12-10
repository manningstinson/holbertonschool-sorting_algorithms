#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t lomuto_partition(int *array, size_t low, size_t high) {
    int pivot = array[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; ++j) {
        if (array[j] <= pivot) {
            ++i;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quick_sort_helper(int *array, size_t low, size_t high) {
    if (low < high) {
        size_t pi = lomuto_partition(array, low, high);
        quick_sort_helper(array, low, pi);
        quick_sort_helper(array, pi + 1, high);
    }
}

void quick_sort(int *array, size_t size) {
    if (size > 1) {
        quick_sort_helper(array, 0, size - 1);
    }
}
