#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GAMES 24000
#define MAX_TITLE_LENGTH 256
#define TOP_N 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int score;
    int year;
} GameReview;

// Comparison function (sorts by score descending)
int compare_reviews(const void *a, const void *b) {
    int ret = ((GameReview *)b)->score - ((GameReview *)a)->score;
    return ret;
}

// Function to remove quotes from a string (in-place modification)
void remove_quotes(char *str) {
    int len = strlen(str);
    if (len > 2 && str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
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

    GameReview *reviews = malloc(MAX_GAMES * sizeof(GameReview));
    if (!reviews) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    int num_reviews = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file) && num_reviews < MAX_GAMES) {
        char *start = line;
        char *end;

        // Find the first comma (end of title)
        int quote_count = 0;
        for (end = start; *end != '\0'; ++end) {
            if (*end == '"') {
                quote_count++;
            } else if (*end == ',' && quote_count % 2 == 0) {
                break;
            }
        }

        if (*end == ',') {
            strncpy(reviews[num_reviews].title, start, end - start);
            reviews[num_reviews].title[end - start] = '\0';
            remove_quotes(reviews[num_reviews].title);

            char *platform = strtok(end + 1, ","); // Skip platform
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


    qsort(reviews, num_reviews, sizeof(GameReview), compare_reviews);

    printf("Top %d Games Overall (All Years):\n", TOP_N);
    for (int i = 0; i < num_reviews && i < TOP_N; ++i) {
        printf("%d. %s (%d, Score: %d)\n", i + 1, reviews[i].title, reviews[i].year, reviews[i].score);
    }

    free(reviews);
    return 0;
}