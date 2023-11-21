#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int max, *counting_array;
    int *temp_array;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    max = array[0];

    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array with size = max + 1 */
    counting_array = malloc((max + 1) * sizeof(int));

    if (counting_array == NULL)
        return;

    /* Initialize counting array elements to 0 */
    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    /* Count occurrences of each element in the input array */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Update counting array to store the position of each element */
    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create a temporary array to store the sorted elements */
    temp_array = malloc(size * sizeof(int));

    if (temp_array == NULL) {
        free(counting_array);
        return;
    }

    /* Build the sorted array using counting array */
    for (i = size - 1; i != SIZE_MAX; i--) 
    {
        counting_array[array[i]]--;
        temp_array[counting_array[array[i]]] = array[i];
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = temp_array[i];

    /* Print the counting array */
    printf("Counting array:");
    print_array(counting_array, max + 1);

    /* Free allocated memory */
    free(counting_array);
    free(temp_array);
}
