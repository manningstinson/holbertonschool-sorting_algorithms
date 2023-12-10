
#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;  // No need to sort if the array is NULL or has less than 2 elements
    }

    size_t i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
        print_array(array, size);
    }
}

