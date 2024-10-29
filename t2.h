#ifndef T2_H_
#define T2_H_

// Maximum length of title
#define MAX_TITLE_LENGTH 256

// GameReview struct for t4_test
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char platform[64];
    int score;
    int year;
} GameReview;

// Swapping functions for sorting algorithms
void swap(int *a, int *b);
void swapReviews(GameReview *a, GameReview *b);

// Selection sort function
void selectionSort(int array[], int size);
// Insertion sort function
void insertionSort(int array[], int size);
// Quick sort functions
void quickSort(int array[], int size);
void quickSortHelper(int array[], int low, int high);
int quickSortPartition(int array[], int low, int high);

// Quick sort implementation for game review struct
int quickSortReviewsPartition(GameReview array[], int low, int high);
void quickSortReviewsHelper(GameReview array[], int low, int high);
void quickSortReviewsAdapter(GameReview array[], int num_reviews);

extern int number_comparisons;
extern int number_swaps;

#endif
