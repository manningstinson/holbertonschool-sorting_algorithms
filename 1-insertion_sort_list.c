#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *insert;
    listint_t *next, *prev;

    current = (*list)->next;

    while (current != NULL)
    {
        insert = current;
        while (insert->prev != NULL && insert->n < insert->prev->n)
        {
            next = insert->next;
            prev = insert->prev;

            if (next != NULL)
                next->prev = prev;

            prev->next = next;
            insert->next = prev;
            insert->prev = prev->prev;
            prev->prev = insert;

            if (insert->prev == NULL)
                *list = insert;

            print_list(*list);
        }
        current = current->next;
    }
}
