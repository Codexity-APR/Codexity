#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* str);

int main() {
    FILE *file = fopen("matrix.txt", "r");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0;

#define MAX_ROWS 100
#define MAX_COLS 100

    int matrix[MAX_ROWS][MAX_COLS];

    while (fgets(line, 100, file)) {
        char** tokens = tokenize(line);
        if (!tokens) {
            printf("Error: Failed to tokenize line %d\n", row);
            return 1;
        }
        int col = 0;
        for (int i = 0; tokens[i]; i++) {
            matrix[row][col] = atoi(tokens[i]);
            col++;
        }
        free(tokens);
        row++;
    }

    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char** tokens = malloc(100 * sizeof(char*));
    if (!tokens) {
        printf("Error: Failed to allocate memory for tokens\n");
        return NULL;
    }
    int token_count = 0;
    int token_size = 100;
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (str[i] =='') {
            tokens[token_count] = malloc(j * sizeof(char));
            if (!tokens[token_count]) {
                printf("Error: Failed to allocate memory for token %d\n", token_count);
                for (int k = 0; k < token_count; k++) {
                    free(tokens[k]);
                }
                free(tokens);
                return NULL;
            }
            for (int k = 0; k < j; k++) {
                tokens[token_count][k] = str[i + k];
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
    tokens[token_count] = malloc(j * sizeof(char));
    if (!tokens[token_count]) {
        printf("Error: Failed to allocate memory for token %d\n", token_count);
        for (int k = 0; k < token_count; k++) {
            free(tokens[k]);
        }
        free(tokens);
        return NULL;
    }
    for (int k = 0; k < j; k++) {
        tokens[token_count][k] = str[i + k];
    }
    tokens[token_count][j] = '\0';
    token_count++;
    tokens = realloc(tokens, token_count * sizeof(char*));
    if (!tokens) {
        printf("Error: Failed to reallocate memory for tokens\n");
        for (int k = 0; k < token_count; k++) {
            free(tokens[k]);
        }
        return NULL;
    }
    return tokens;
}