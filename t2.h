#ifndef T2_H_
#define T2_H_

void swap(int *a, int *b);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void quickSort(int array[], int size);
void quickSortHelper(int array[], int low, int high);
int quickSortPartition(int array[], int low, int high);

extern int number_comparisons;
extern int number_swaps;

#endif
