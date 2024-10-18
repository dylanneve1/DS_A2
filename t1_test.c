#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "t1.h"

int main() {
    // Set the array size
    int size = 10;
    int array[MAX_ARRAY_SIZE];

    // Seed the random number generator
    srand(time(NULL));

    printf("Filling array with ascending numbers:\n");
    fill_ascending(array, size);
    printArray(array, size);

    printf("Filling array with descending numbers:\n");
    fill_descending(array, size);
    printArray(array, size);

    printf("Filling array with uniform numbers:\n");
    fill_uniform(array, size);
    printArray(array, size);

    printf("Filling array with duplicates allowed (random numbers):\n");
    fill_with_duplicates(array, size);
    printArray(array, size);

    printf("Filling array with unique numbers (no duplicates, shuffled):\n");
    fill_without_duplicates(array, size);
    printArray(array, size);

    return 0;
}
