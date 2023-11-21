#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the doubly linked list
* @node_a: First node to swap
* @node_b: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
listint_t *temp_prev_a, *temp_next_a;

temp_prev_a = node_a->prev;
temp_next_a = node_a->next;

if (temp_prev_a)
temp_prev_a->next = node_b;
else
*list = node_b;

node_b->prev = temp_prev_a;
node_b->next = node_a;
node_a->prev = node_b;
node_a->next = node_b->next;

if (temp_next_a)
temp_next_a->prev = node_a;
}

/**
* cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker Sort algorithm
* @list: Pointer to the doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

do {
swapped = 0;
for (current = *list; current->next != NULL; current = current->next) {
if (current->n > current->next->n) {
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
}

if (!swapped)
break;

swapped = 0;
for (; current->prev != NULL; current = current->prev) {
if (current->n < current->prev->n) {
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
}
} while (swapped);
}

