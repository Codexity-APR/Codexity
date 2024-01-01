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
    // Count the number of rows in the file
    while (fgets(line, sizeof(line), file)) {
        row++;
    }

    // Allocate memory for the matrix
    int** matrix = (int**) malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*) malloc(row * sizeof(int));
    }

    // Reset the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Read the file and populate the matrix
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        char** tokens = tokenize(line);
        for (int j = 0; j < row; j++) {
            matrix[i][j] = atoi(tokens[j]);
        }
        free(tokens);
        i++;
    }

    // Print the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Close the file
    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char** tokens = (char**) malloc(100 * sizeof(char*));
    char* token = strtok((char*) str, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = (char*) malloc(strlen(token) * sizeof(char));
        strcpy(tokens[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    tokens[i] = NULL;
    return tokens;
}
