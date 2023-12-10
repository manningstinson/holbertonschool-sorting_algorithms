/* 0-bubble_sort.c */
#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b) {
    int temp;
    size_t i, j;

    if (a == NULL || b == NULL) {
        return;  /* Check if pointers are NULL */
    }

    temp = *a;
    *a = *b;
    *b = temp;

    if (array == NULL || size < 2) {
        return;  /* No need to sort if the array is NULL or has less than 2 elements */
    }

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
        print_array(array, size);
    }
}
