
#include "sort.h"

/**
* insertion_sort_list - Sorts a d/linked list of integers in ascending order
*using the Insertion sort algorithm.
*
* @list: Pointer to the pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *tmp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;


current = (*list)->next;
while (current != NULL)
{
prev = current->prev;
while (prev != NULL && prev->n > current->n)
{
tmp = prev->prev;
if (prev->next != NULL)
prev->next->prev = prev;
prev->next = current->next;
if (current->next != NULL)
current->next->prev = prev;
prev->prev = current;
current->next = prev;
current->prev = tmp;
if (tmp != NULL)
tmp->next = current;
else
*list = current;

print_list(*list);
prev = current->prev;
}
current = current->next;
}
}
