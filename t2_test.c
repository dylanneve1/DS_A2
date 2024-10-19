#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "t1.h"
#include "t2.h"

// Function to reset the array to its original state
void resetArray(int *original, int *array, int size) {
    memcpy(array, original, size * sizeof(int));
}

// Function to test a specific sorting algorithm
void testSortingAlgorithm(void (*sortFunc)(int*, int), const char *sortName, int *array, int size) {
    number_comparisons = 0;
    number_swaps = 0;

    printf("\n-- %s --\n", sortName);
    printf("Original array:\n");
    printArray(array, size);

    sortFunc(array, size);

    printf("Sorted array:\n");
    printArray(array, size);
}

// Main function to test all sorting algorithms
void testSortingAlgorithms(int *originalArray, int size, const char *testCaseName) {
    int *array = (int *)malloc(size * sizeof(int));

    if (!array) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("=== %s ===\n", testCaseName);

    // Test Selection Sort
    resetArray(originalArray, array, size);
    testSortingAlgorithm(selectionSort, "Selection Sort", array, size);

    // Test Insertion Sort
    resetArray(originalArray, array, size);
    testSortingAlgorithm(insertionSort, "Insertion Sort", array, size);

    // Test Quick Sort
    resetArray(originalArray, array, size);
    testSortingAlgorithm(quickSort, "Quick Sort", array, size);

    printf("\n----------------------------------------\n\n");

    // Free allocated memory
    free(array);
}

int main() {
    int size = 10;
    int array[10];

    // Seed the random number generator
    srand(time(NULL));

    // Define test cases with corresponding filling functions and names
    struct {
        void (*fillFunction)(int *, int);
        const char *testCaseName;
    } testCases[] = {
        { fill_ascending, "Ascending Array" },
        { fill_descending, "Descending Array" },
        { fill_uniform, "Uniform Array" },
        { fill_with_duplicates, "Array with Duplicates" },
        { fill_without_duplicates, "Unique Shuffled Array" }
    };

    int numberOfTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for(int i = 0; i < numberOfTestCases; i++) {
        printf("Testing sorting algorithms with %s:\n", testCases[i].testCaseName);
        // Fill the array using the specified function
        testCases[i].fillFunction(array, size);
        // Test all sorting algorithms on the filled array
        testSortingAlgorithms(array, size, testCases[i].testCaseName);
    }

    return 0;
}