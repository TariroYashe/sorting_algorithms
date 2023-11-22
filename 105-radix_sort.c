#include "sort.h"

/**
* getMax - Helper function to get the maximum element in an array
*
* @array: The array to find the maximum element from
* @size: Number of elements in @array
* Return: The maximum element in the array
*/
int getMax(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
{
max = array[i];
}
}
return (max);
}

/**
* countSort - Helper function to perform counting sort based on a digit
*
* @array: The array to be sorted
* @size: Number of elements in @array
* @exp: The current digit's place value
*/
void countSort(int *array, size_t size, int exp)
{
const int base = 10;
int *output = malloc(size * sizeof(int));
int *count = malloc(base * sizeof(int));
size_t i;
int j;

if (output == NULL || count == NULL)
{
/* Handle memory allocation failure if necessary */
free(output);
free(count);
return;
}

/* Initialize count array */
for (j = 0; j < base; j++)
{
count[j] = 0;
}

/* Count occurrences of digits at the current place value */
for (i = 0; i < size; i++)
{
count[(array[i] / exp) % base]++;
}

/* Update count to store the position of each digit in the output array */
for (j = 1; j < base; j++)
{
count[j] += count[j - 1];
}

/* Build the output array */
for (i = size - 1; i < SIZE_MAX; i--)
{
output[count[(array[i] / exp) % base] - 1] = array[i];
count[(array[i] / exp) % base]--;
}

/* Copy the output array back to the original array */
for (i = 0; i < size; i++) 
{
array[i] = output[i];
}

free(output);
free(count);
}
/**
* radix_sort - Sorts an array of integers in ascending order using Radix sort
*
* @array: The array to be sorted
* @size: Number of elements in @array
*/
void radix_sort(int *array, size_t size)
{
int max = getMax(array, size);
size_t exp;

for (exp = 1; max / exp > 0; exp *= 10)
{
countSort(array, size, exp);
print_array(array, size);
}
}
