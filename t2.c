#include <stdio.h> 
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;


void selectionSort(int array[], int size) { 
    for (int i = 0; i < size; i++) {
      int minum = i;
      for (int j = i + 1; j < size; j++) {
        if (array[j] < array[minum]) {
          minum = j;
        }
      }
      if (minum != i) {
        int cached = array[minum];
        array[minum] = array[i];
        array[i] = cached;
      }
    }
} 

void insertionSort(int array[], int size) {
    //TODO
}

void quickSort(int array[], int size) {
    //TODO
}
