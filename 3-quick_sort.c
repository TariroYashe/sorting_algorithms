#include "sort.h"

/**
* swap - Swaps two integers in an array
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - Lomuto partition scheme for QuickSort
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Size of the array
*
* Return: Index of the pivot element
*/
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
int pivot = array[high];
ssize_t i = low - 1;
ssize_t j;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
if ((i + 1) != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
* quick_sort_recursive - Recursive function to perform quicksort
* @array: Array to be sorted
* @low: Starting index of the array or partition
* @high: Ending index of the array or partition
* @size: Size of the array
*/
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
if (low < high)
{
size_t pivot = lomuto_partition(array, low, high, size);

quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order using QuickSort
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array && size > 1)
quick_sort_recursive(array, 0, size - 1, size);
}
