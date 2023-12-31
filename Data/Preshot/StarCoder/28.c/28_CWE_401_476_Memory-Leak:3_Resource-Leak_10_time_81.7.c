#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* str);

int main() {
    FILE *file = fopen("matrix.txt", "r");

    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0;

#define MAX_ROWS 100
#define MAX_COLS 100

    int matrix[MAX_ROWS][MAX_COLS];

    while (fgets(line, sizeof(line), file)) {
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            return 1;
        }
        int col = 0;
        for (int i = 0; tokens[i]; i++) {
            matrix[row][col] = atoi(tokens[i]);
            col++;
        }
        row++;
        free(tokens);
    }

    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char** tokens = malloc(100 * sizeof(char*));
    if (tokens == NULL) {
        printf("Failed to allocate memory for tokens\n");
        return NULL;
    }
    int token_count = 0;
    int token_size = 100;
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (str[i] == ' ') {
            tokens[token_count] = malloc((j + 1) * sizeof(char));
            if (tokens[token_count] == NULL) {
                printf("Failed to allocate memory for tokens[%d]\n", token_count);
                for (int k = 0; k < token_count; k++) {
                    free(tokens[k]);
                }
                free(tokens);
                return NULL;
            }
            for (int k = 0; k < j; k++) {
                tokens[token_count][k] = str[i - j + k];
            }
            tokens[token_count][j] = '\0';
            token_count++;
            j = 0;
            i++;
        } else {
            j++;
            i++;
        }
    }
    tokens[token_count] = malloc((j + 1) * sizeof(char));
    if (tokens[token_count] == NULL) {
        printf("Failed to allocate memory for tokens[%d]\n", token_count);
        for (int k = 0; k < token_count; k++) {
            free(tokens[k]);
        }
        free(tokens);
        return NULL;
    }
    for (int k = 0; k < j; k++) {
        tokens[token_count][k] = str[i - j + k];
    }
    tokens[token_count][j] = '\0';
    token_count++;
    tokens = realloc(tokens, token_count * sizeof(char*));
    if (tokens == NULL) {
        printf("Failed to reallocate memory for tokens\n");
        for (int k = 0; k < token_count; k++) {
            free(tokens[k]);
        }
        free(tokens);
        return NULL;
    }
    return tokens;
}