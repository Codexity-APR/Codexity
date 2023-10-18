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
    
    char** matrix = (char**)malloc(sizeof(char*) * 100); // Assuming the matrix has at most 100 rows

    while (fgets(line, sizeof(line), file)) {
        matrix[row] = (char*)malloc(sizeof(char) * strlen(line) + 1); // Allocate memory for each row
        strcpy(matrix[row], line);
        row++;
    }

    fclose(file);

    // Printing the matrix
    for (int i = 0; i < row; i++) {
        printf("%s", matrix[i]);
    }

    // Freeing the memory
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}