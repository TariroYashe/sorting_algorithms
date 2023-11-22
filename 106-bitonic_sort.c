#include "sort.h"
/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence in given order
 * @array: The array to be sorted
 * @low: Starting index of the subarray to be sorted
 * @count: Number of elements in the subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
size_t k = count / 2;
if (count > 1)
{
printf("Merging [%lu/%lu] (UP):\n", low, low + count - 1);
print_array(array + low, count);

bitonic_sort_recursive(array, low, k, 1);

printf("Merging [%lu/%lu] (DOWN):\n", low + k, low + count - 1);
print_array(array + low + k, count - k);

bitonic_sort_recursive(array, low + k, k, 0);

bitonic_merge(array, low, count, dir);
}
}

/**
 * bitonic_merge - Merge two subarrays of the given array
 * @array: The array to be sorted
 * @low: Starting index of the first subarray
 * @count: Number of elements in each subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
if (count > 1)
{
size_t k = count / 2;
size_t i;

for (i = low; i < low + k; ++i)
{
if ((array[i] > array[i + k]) == dir)
{

int temp = array[i];
array[i] = array[i + k];
array[i + k] = temp;
}
}

bitonic_merge(array, low, k, dir);
bitonic_merge(array, low + k, k, dir);
}
}

/**
 * bitonic_sort - Sorts an array of int in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
if (array && size > 1)
{
bitonic_sort_recursive(array, 0, size, 1);
}
}
