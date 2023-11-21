#include "sort.h"

/**
* insertion_sort_list - Sorts a d/linked list of integers in ascending order
* using the Insertion sort algorithm.
*
* @list: Pointer to the pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *next;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
next = current->next;
prev = current->prev;

while (prev != NULL && prev->n > current->n)
{
prev->next = current->next;

if (current->next != NULL)
current->next->prev = prev;

current->next = prev;
current->prev = prev->prev;

if (prev->prev != NULL)
prev->prev->next = current;
else
*list = current;

prev->prev = current;
prev = current->prev;
}

current = next;
}
}
