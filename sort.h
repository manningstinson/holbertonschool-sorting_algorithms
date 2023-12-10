#ifndef SORT_H
#define SORT_H

#include <stddef.h>

typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void quick_sort(int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void quick_sort_helper(int *array, size_t low, size_t high);
void swap(int *a, int *b);

#endif /* SORT_H */
