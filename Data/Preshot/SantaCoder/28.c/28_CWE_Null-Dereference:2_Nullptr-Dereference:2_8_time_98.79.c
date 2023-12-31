#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

char** tokenize(const char* str);

int main() {
    FILE *file = fopen("matrix.txt", "r");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0, col = 0;
    int matrix[MAX_ROWS][MAX_COLS];

    while (fgets(line, 100, file) != NULL) {
        char** tokens = tokenize(line);
        col = 0;

        for (int i = 0; tokens[i] != NULL; i++) {
            matrix[row][col++] = atoi(tokens[i]);
        }

        row++;

        free(tokens);
    }

    fclose(file);

    // Print the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

char** tokenize(const char* str) {
    char** tokens = (char**)malloc(sizeof(char*) * 10);

    int i = 0;
    char* token = strtok((char*)str, " ");

    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }

    tokens[i] = NULL;

    return tokens;
}