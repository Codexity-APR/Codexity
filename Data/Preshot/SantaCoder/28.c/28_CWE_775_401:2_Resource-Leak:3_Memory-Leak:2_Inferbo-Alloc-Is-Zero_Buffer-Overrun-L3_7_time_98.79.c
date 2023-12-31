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

#ifdef __cplusplus
    char *buf = (char*)malloc(100);
#else
    char *buf = (char*)malloc(100 * sizeof(char));
#endif

    char **matrix = (char**)malloc(row * sizeof(char*));
    if (!matrix) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    while (fgets(line, 100, file)) {
        row++;

        matrix = (char**)realloc(matrix, row * sizeof(char*));
        if (!matrix) {
            printf("Failed to allocate memory\n");
            return 1;
        }

        matrix[row - 1] = (char*)malloc(strlen(line) + 1);
        if (!matrix[row - 1]) {
            printf("Failed to allocate memory\n");
            return 1;
        }

        strcpy(matrix[row - 1], line);
    }

    if (buf) {
        free(buf);
    }

    fclose(file);

    for (int i = 0; i < row; i++) {
        printf("%s", matrix[i]);
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}