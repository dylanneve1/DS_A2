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
    // Loop through every element in array
    for (int i = 0; i < size - 1; i++) {
        // Set assumed minimum to current
        int minimum = i;
        // For every element after that check if it's smaller
        for (int j = i + 1; j < size; j++) {
            number_comparisons++; // Increment comparisons count
            // If it is smaller then set minimum to j
            if (array[j] < array[minimum]) {
                minimum = j;
            }
        }
        swap(&array[minimum], &array[i]);
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
} /* Time Complexity: O(n^2) */

// Quick Sort Partition function
// - Using Hoare's parition scheme
int quickSortPartition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        // Find the leftmost element greater or equal to pivot
        do {
            i++;
            number_comparisons++;
        } while (array[i] < pivot);

        // Find the rightmost element smaller than or equal to pivot
        do {
            j--;
            number_comparisons++;
        } while (array[j] > pivot);

        // If the two pointers met
        if (i >= j) {
            return j;
        }

        swap(&array[i], &array[j]);
    }
}

// Quick Sort Random Pivot Generator
// - In Hoare partition the low element
//   is selected as first pivot
int quickSortPartitionRandom(int array[], int low, int high) {
    // Random number between low and high
    int random_index = low + rand() % (high - low);
    // Swap the randomly generated index to pivot position
    swap(&array[random_index], &array[low]);
    return quickSortPartition(array, low, high);
}

// Quick Sort Recursive Helper
void quickSortHelper(int array[], int low, int high) {
    if (low < high) {
        int pi = quickSortPartitionRandom(array, low, high);
        quickSortHelper(array, low, pi);
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
    int i = low - 1;
    int j = high + 1;

    while (1) {
        // Find the leftmost element greater or equal to pivot
        do {
            i++;
            number_comparisons++;
        } while (array[i].score < pivot);

        // Find the rightmost element smaller than or equal to pivot
        do {
            j--;
            number_comparisons++;
        } while (array[j].score > pivot);

        // If the two pointers met
        if (i >= j) {
            return j;
        }

        swapReviews(&array[i], &array[j]);
    }
}

// Quick Sort Random Pivot Generator
// - In Hoare partition the low element
//   is selected as first pivot
int quickSortReviewsPartitionRandom(GameReview array[], int low, int high) {
    // Random number between low and high
    int random_index = low + rand() % (high - low);
    // Swap the randomly generated index to pivot position
    swapReviews(&array[random_index], &array[low]);
    return quickSortReviewsPartition(array, low, high);
}

// Recursive Quick Sort Helper for GameReview Array
void quickSortReviewsHelper(GameReview array[], int low, int high) {
    if (low < high) {
        int pi = quickSortReviewsPartitionRandom(array, low, high);
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
