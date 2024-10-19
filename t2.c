#include <stdio.h> 
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

// Function to swap two integer values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort Algorithm
void selectionSort(int array[], int size) { 
    for (int i = 0; i < size; i++) {
      int minum = i;
      for (int j = i + 1; j < size; j++) {
        if (array[j] < array[minum]) {
          minum = j;
        }
      }
      if (minum != i) {
        swap(&array[minum], &array[i]);
      }
    }
} /* Time Complexity: O(n^2) */

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        if (array[j] <= key) {
          continue;
        }

        while (j >= 0 && array[j] > key) {
          array[j + 1] = array[j];
          j--;
        }

        array[j+1] = key;
    }
}

int quickSortPartition(int array[], int low, int high) {
    int p = array[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (array[i] <= p && i <= high - 1) {
            i++;
        }
        while (array[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[low], &array[j]);
    return j;
}

void quickSortHelper(int array[], int low, int high) {
    if (low < high) {
        int pi = quickSortPartition(array, low, high);
        quickSortHelper(array, low, pi - 1);
        quickSortHelper(array, pi + 1, high);
    }
}

void quickSort(int array[], int size) {
    quickSortHelper(array, 0, size - 1);
}
