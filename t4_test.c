#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GAMES 100
#define MAX_TITLE_LENGTH 256
#define MAX_PLATFORM_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char platform[MAX_PLATFORM_LENGTH];
    int score;
    int year;
} GameReview;

// Comparison function (sorts by score descending)
int compare_reviews(const void *a, const void *b) {
    return ((GameReview *)b)->score - ((GameReview *)a)->score;
}

// Function to remove quotes from a string
void remove_quotes(char *str) {
    int len = strlen(str);
    if (len > 2 && str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}


void find_most_popular_overall(GameReview reviews[], int num_reviews) {
    qsort(reviews, num_reviews, sizeof(GameReview), compare_reviews);

    printf("Top Games Overall (Last 20 Years):\n");
    for (int i = 0; i < num_reviews && i < 10; ++i) { 
        printf("%d. %s (%d, Score: %d)\n", i + 1, reviews[i].title, reviews[i].year, reviews[i].score);
    }
}

void find_top_games_per_year(GameReview reviews[], int num_reviews) {
    printf("\nTop 5 Games Per Year:\n");
    for (int year = 2024; year >= 2005; year--) {
        printf("Year %d:\n", year);
        int count = 0;
        for (int i = 0; i < num_reviews; i++) {
            if (reviews[i].year == year && count < 5) {
                printf("  %s, Score: %d\n", reviews[i].title, reviews[i].score);
                count++;
            } else if (count >= 5 && reviews[i].year == year) {
                continue;
            }
        }
        if (count == 0) {
            printf("No data available\n");
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <game_reviews_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    GameReview reviews[MAX_GAMES];
    int num_reviews = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file) && num_reviews < MAX_GAMES) {
        char *title = strtok(line, ",");
        char *platform = strtok(NULL, ",");
        char *score_str = strtok(NULL, ",");
        char *year_str = strtok(NULL, ",");

        if (title && platform && score_str && year_str) {
            remove_quotes(title);
            strncpy(reviews[num_reviews].title, title, MAX_TITLE_LENGTH - 1);
            reviews[num_reviews].title[MAX_TITLE_LENGTH - 1] = '\0';

            remove_quotes(platform);
            strncpy(reviews[num_reviews].platform, platform, MAX_PLATFORM_LENGTH - 1);
            reviews[num_reviews].platform[MAX_PLATFORM_LENGTH - 1] = '\0';

            remove_quotes(score_str);
            reviews[num_reviews].score = atoi(score_str);

            remove_quotes(year_str);
            reviews[num_reviews].year = atoi(year_str);

            num_reviews++;
        }
    }
    fclose(file);

    find_most_popular_overall(reviews, num_reviews);
    qsort(reviews, num_reviews, sizeof(GameReview), compare_reviews);
    find_top_games_per_year(reviews, num_reviews);

    return 0;
}
