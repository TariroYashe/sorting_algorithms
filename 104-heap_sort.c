#include "sort.h"

/**
* sift_down - Perform the sift-down operation in the heap sort algorithm
*
* @array: The array to be sorted
* @size: Size of the array
* @root: The root index of the heap
* @max_size: The maximum size of the heap
*/
void sift_down(int *array, size_t size, size_t root, size_t max_size)
{
size_t left_child, right_child, largest, temp;

while ((left_child = 2 * root + 1) < max_size)
{
right_child = left_child + 1;
largest = (right_child < max_size && array[right_child] > array[left_child])
? right_child
: left_child;

if (array[largest] > array[root])
{
temp = array[root];
array[root] = array[largest];
array[largest] = temp;
print_array(array, size);
root = largest;
}
else
break;
}
}

/**
* heapify - Build a max heap from the array
*
* @array: The array to be sorted
* @size: Size of the array
*/
void heapify(int *array, size_t size)
{
size_t i;

for (i = (size / 2) - 1; i > 0; i--)
sift_down(array, size, i, size);
}

/**
* heap_sort - Sorts an array of integers in ascending order
*
* @array: The array to be sorted
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
size_t i;
int temp;

if (!array || size < 2)
return;

heapify(array, size);

for (i = size - 1; i > 0; i--)
{
temp = array[0];
array[0] = array[i];
array[i] = temp;
print_array(array, size);
sift_down(array, size, 0, i);
}
}
