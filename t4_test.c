#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t1.h"
#include "t2.h"

#define MAX_GAMES 24000
#define TOP_N 100

// Simple function to strip leading/trailing quotes and remove trailing newline character
void remove_quotes(char *str) {
    // Check if the first character is a quote and remove it
    if (str[0] == '"') {
        memmove(str, str + 1, strlen(str));
    }

    // Get the length of the string after modification
    int len = strlen(str);

    // Check if the last character is a quote and remove it
    if (str[len - 1] == '"') {
        str[len - 1] = '\0';
    }
}

// Function to print the top N game reviews
void printTopNGames(GameReview *reviews, int size, int top_n) {
    printf("Top %d Games:\n", top_n);
    printf("%-5s %-70s %-30s %-10s %-10s\n", "Rank", "Title", "Platform", "Score", "Year");
    for (int i = 0; i < top_n && i < size; i++) {
        printf("%-5d %-70s %-30s %-10d %-10d\n", i + 1, reviews[i].title, reviews[i].platform, reviews[i].score, reviews[i].year);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <game_reviews_file>\n", argv[0]);
        return 1;
    }
    
    // Clear screen
    system("clear");

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file");
        return 1;
    }

    GameReview *reviews = malloc(MAX_GAMES * sizeof(GameReview));
    if (!reviews) {
        printf("Memory allocation failed");
        fclose(file);
        return 1;
    }

    int num_reviews = 0;
    char line[1024];

    // Remove header
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && num_reviews < MAX_GAMES) {
        // Tokenize and parse CSV fields
        char *title = strtok(line, ",");
        char *platform = strtok(NULL, ",");
        char *score = strtok(NULL, ",");
        char *year = strtok(NULL, "\n");

        // Strip quotes from parsed fields
        remove_quotes(title);

        strcpy(reviews[num_reviews].title, title);
        strcpy(reviews[num_reviews].platform, platform);

        reviews[num_reviews].score = atoi(score);
        reviews[num_reviews].year = atoi(year);

        num_reviews++;
    }
    fclose(file);

    quickSortReviewsAdapter(reviews, num_reviews);
    printTopNGames(reviews, num_reviews, TOP_N);

    free(reviews);
    return 0;
}