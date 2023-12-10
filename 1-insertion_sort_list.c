#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (*list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    listint_t *insert;

    current = (*list)->next;

    while (current != NULL)
    {
        insert = current;
        while (insert->prev != NULL && insert->n < insert->prev->n)
        {
            if (insert->next != NULL)
                insert->next->prev = insert->prev;
            insert->prev->next = insert->next;
            insert->next = insert->prev;
            insert->prev = insert->prev->prev;
            insert->next->prev = insert;
        }
        current = current->next;
    }
}
