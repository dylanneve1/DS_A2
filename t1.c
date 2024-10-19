#include <stdio.h>
#include <stdlib.h>
#include "t1.h"

// Fills the array with ascending, consecutive numbers, starting from 0.
void fill_ascending(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
} /* Time Complexity: O(n) */

// Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (size - 1) - i;
    }
} /* Time Complexity: O(n) */

// Fills the array with uniform numbers.
void fill_uniform(int *array, int size) {
    int filler = rand() % 10;
    for (int i = 0; i < size; i++) {
        array[i] = filler;
    }
} /* Time Complexity: O(n) */

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
} /* Time Complexity: O(n) */

// Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size) {
    // Dynamically allocate the nodupli array
    int *nodupli = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        int value = rand() % size;
        while (nodupli[value] == 1) {
            value = rand() % size;
        }
        array[i] = value;
        nodupli[value] = 1;
    }

    // Free the allocated memory
    free(nodupli);
} /* Time Complexity: O(n^2) */

// Runs through and prints values in array
void printArray(int* array, int size) {
    int i;
    for(i=0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
} /* Time Complexity: O(n) */
