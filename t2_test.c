#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "t1.h"
#include "t2.h"

void testSortingAlgorithms(int *array, int size) {
    printf("Original array:\n");
    printArray(array, size);
    printf("Selection Sort:\n");
    selectionSort(array, size);
    printArray(array, size);;
}

int main() {
    int size = 10;
    int array[MAX_ARRAY_SIZE];
    
    // Seed the random number generator
    srand(time(NULL));

    printf("Testing sorting algorithms with ascending array:\n");
    fill_ascending(array, size);
    testSortingAlgorithms(array, size);

    printf("\nTesting sorting algorithms with descending array:\n");
    fill_descending(array, size);
    testSortingAlgorithms(array, size);

    printf("\nTesting sorting algorithms with uniform array:\n");
    fill_uniform(array, size);
    testSortingAlgorithms(array, size);

    printf("\nTesting sorting algorithms with duplicates allowed array:\n");
    fill_with_duplicates(array, size);
    testSortingAlgorithms(array, size);

    printf("\nTesting sorting algorithms with unique shuffled array:\n");
    fill_without_duplicates(array, size);
    testSortingAlgorithms(array, size);

    return 0;
}