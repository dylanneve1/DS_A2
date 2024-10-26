#ifndef T2_H_
#define T2_H_

#define MAX_TITLE_LENGTH 256

// GameReview struct for t4_test
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int score;
    int year;
} GameReview;

void swap(int *a, int *b);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void quickSort(int array[], int size);
void quickSortHelper(int array[], int low, int high);
int quickSortPartition(int array[], int low, int high);

// For t4_test
int quickSortReviewsPartition(GameReview array[], int low, int high);
void quickSortReviewsHelper(GameReview array[], int low, int high);
void gameReviewAdapter(GameReview array[], int num_reviews);

extern int number_comparisons;
extern int number_swaps;

#endif
