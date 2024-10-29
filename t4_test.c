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
    printf("%-5s %-90s %-30s %-10s %-10s\n", "Rank", "Title", "Platform", "Score", "Year");
    for (int i = 0; i < top_n && i < size; i++) {
        printf("%-5d %-90s %-30s %-10d %-10d\n", i + 1, reviews[i].title, reviews[i].platform, reviews[i].score, reviews[i].year);
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
        char *start = line;
        char *end;

        // Find the first comma (end of title)
        int quote_count = 0;
        for (end = start; *end != '\0'; ++end) {
            if (*end == '"') {
                quote_count++;
            } else if (*end == ',' && quote_count % 2 == 0) { // Check if amount of quotes has been even
                break;
            }
        }

        if (*end == ',') {
            strncpy(reviews[num_reviews].title, start, end - start);
            reviews[num_reviews].title[end - start] = '\0';
            remove_quotes(reviews[num_reviews].title);

            char *platform = strtok(end + 1, ","); // Skip platform

            strcpy(reviews[num_reviews].platform, platform);

            char *score_str = strtok(NULL, ",");
            char *year_str = strtok(NULL, ",");

            if (score_str && year_str) { // Check for missing fields
                remove_quotes(score_str);
                reviews[num_reviews].score = atoi(score_str);

                remove_quotes(year_str);
                reviews[num_reviews].year = atoi(year_str);

                num_reviews++;
            }
        }
    }
    fclose(file);

    quickSortReviewsAdapter(reviews, num_reviews);
    printTopNGames(reviews, num_reviews, TOP_N);

    free(reviews);
    return 0;
}