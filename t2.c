#include <stdio.h> 
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

// Function to swap two integer values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    number_swaps++; // Increment the swap count each time this function is called
}

// Selection Sort Algorithm
void selectionSort(int array[], int size) { 
    for (int i = 0; i < size; i++) {
        int minum = i;
        for (int j = i + 1; j < size; j++) {
            number_comparisons++; // Increment comparisons count
            if (array[j] < array[minum]) {
                minum = j;
            }
        }
        if (minum != i) {
            swap(&array[minum], &array[i]);
        }
    }
} /* Time Complexity: O(n^2) */

// Insertion Sort Algorithm
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        number_comparisons++; // Comparison for array[j] <= key
        if (array[j] <= key) {
            continue;
        }

        while (j >= 0 && array[j] > key) {
            number_comparisons++; // Increment comparisons count
            array[j + 1] = array[j];
            number_swaps++;
            j--;
        }

        array[j + 1] = key;
    }
}

// Quick Sort Partition function
int quickSortPartition(int array[], int low, int high) {
    int p = array[low];  // Choose the pivot as the first element
    int i = low;
    int j = high;
    while (i < j) {
        number_comparisons++; // Increment comparisons count for array[i] <= p
        while (array[i] <= p && i <= high - 1) {
            i++;
            number_comparisons++; // Increment comparisons for each loop iteration
        }

        number_comparisons++; // Increment comparisons count for array[j] > p
        while (array[j] >= p && j >= low + 1) {
            j--;
            number_comparisons++; // Increment comparisons for each loop iteration
        }

        if (i < j) {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[low], &array[j]);
    return j;  // Return the partition index
}

// Quick Sort Recursive Helper
void quickSortHelper(int array[], int low, int high) {
    if (low < high) {
        int pi = quickSortPartition(array, low, high);
        quickSortHelper(array, low, pi - 1);
        quickSortHelper(array, pi + 1, high);
    }
}

// Quick Sort function
void quickSort(int array[], int size) {
    quickSortHelper(array, 0, size - 1);
}
