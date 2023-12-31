#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printfunctions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Functions to Sort algorthms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b);
void counting_sort(int *array, size_t size);
void merge(int *array, size_t l, size_t m, size_t r);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t max_size);
void heapify(int *array, size_t size);
void radix_sort(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
int getMax(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);
void quick_sort_hoare(int *array, size_t size);

#endif
