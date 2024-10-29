#include <stdio.h> 
#include <stdlib.h> 
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

// Function to swap two review structs
void swapReviews(GameReview *a, GameReview *b) {
    GameReview temp = *a;
    *a = *b;
    *b = temp;
    number_swaps++; // Increment the swap count each time this function is called
}

// Selection Sort Algorithm
void selectionSort(int array[], int size) { 
    for (int i = 0; i < size; i++) {
        int minimum = i;
        for (int j = i + 1; j < size; j++) {
            number_comparisons++; // Increment comparisons count
            if (array[j] < array[minimum]) {
                minimum = j;
            }
        }
        if (minimum != i) {
            swap(&array[minimum], &array[i]);
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

        while (j >= 0) {
            number_comparisons++; // For each comparison in the while condition
            if (array[j] > key) {
                array[j + 1] = array[j];
                number_swaps++;
                j--;
            } else {
                break;
            }
        }

        array[j + 1] = key;
    }
} /* Time Complexity: O(n^2) */

// Quick Sort Partition function
int quickSortPartition(int array[], int low, int high) {
    int p = array[low];
    int i = low;
    int j = high;
    while (i < j) {
        number_comparisons++;
        while (array[i] <= p && i < high) {
            i++;
            number_comparisons++; // Increment comparison count
        }

        while (array[j] >= p && j > low) {
            j--;
            number_comparisons++; // Increment comparison count
        }

        number_comparisons++; // Increment comparison count
        if (i < j) {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[low], &array[j]);
    return j;
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

// Partition Function for Quick Sort on GameReview Array
int quickSortReviewsPartition(GameReview array[], int low, int high) {
    int pivot = array[low].score; 
    int i = low;
    int j = high;

    while (i < j) {
        while (array[i].score >= pivot && i < high) {
            i++;
        }

        while (array[j].score <= pivot && j > low) {
            j--;
        }

        if (i < j) {
            swapReviews(&array[i], &array[j]);
        }
    }
    swapReviews(&array[low], &array[j]);
    return j;
}

// Recursive Quick Sort Helper for GameReview Array
void quickSortReviewsHelper(GameReview array[], int low, int high) {
    if (low < high) {
        int pi = quickSortReviewsPartition(array, low, high);
        quickSortReviewsHelper(array, low, pi - 1);
        quickSortReviewsHelper(array, pi + 1, high);
    }
}

// Adapter Function to Sort GameReview Array Based on Score
void quickSortReviewsAdapter(GameReview array[], int num_reviews) {
    if (array == NULL || num_reviews <= 1) {
        return;
    }
    quickSortReviewsHelper(array, 0, num_reviews - 1);
}
