#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * First subarray is array[l..m]
 * Second subarray is array[m+1..r]
 * @array: The array to be sorted
 * @l: Left index of the subarray
 * @m: Middle index of the subarray
 * @r: Right index of the subarray
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    /* Create temporary arrays */
    int *left = malloc(sizeof(int) * n1);
    int *right = malloc(sizeof(int) * n2);

    /* Copy data to temporary arrays left[] and right[] */
    for (i = 0; i < n1; i++)
        left[i] = array[l + i];
    for (j = 0; j < n2; j++)
        right[j] = array[m + 1 + j];

    /* Merge the temporary arrays back into array[l..r] */
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left[], if there are any */
    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right[], if there are any */
    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }

    /* Free the temporary arrays */
    free(left);
    free(right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (size > 1) {
        size_t mid = size / 2;
        size_t i;
        
        /* Create left and right subarrays */
        int *left = array;
        int *right = array + mid;

        /* Recursively sort the left and right subarrays */
        merge_sort(left, mid);
        merge_sort(right, size - mid);

        /* Merge the sorted subarrays */
        merge(array, 0, mid - 1, size - 1);

        /* Print the current state of the array after merging */
        printf("Merging...\n");
        printf("[left]: ");
        for (i = 0; i < mid; i++)
            printf("%d%s", left[i], (i < mid - 1) ? ", " : "");
        printf("\n[right]: ");
        for (i = 0; i < size - mid; i++)
            printf("%d%s", right[i], (i < size - mid - 1) ? ", " : "");
        printf("\n");
        printf("[Done]: ");
        print_array(array, size);
    }
}
