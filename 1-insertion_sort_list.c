#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current->next;

        while (current->prev && current->n < current->prev->n)
        {
            listint_t *prev = current->prev;
            listint_t *next = current->next;

            prev->next = next;
            if (next)
                next->prev = prev;
            current->next = prev;
            current->prev = prev->prev;
            current->next->prev = current;

            if (current->prev)
                current->prev->next = current;
            else
                *list = current;

            print_list(*list);
        }

        current = temp;
    }
}
