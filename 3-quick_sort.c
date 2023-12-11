#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, size_t low, size_t high) {
    int pivot = array[high];
    size_t i = low - 1;

    for (size_t j = low; j <= high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    return i;
}

void quick_sort(int *array, size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
