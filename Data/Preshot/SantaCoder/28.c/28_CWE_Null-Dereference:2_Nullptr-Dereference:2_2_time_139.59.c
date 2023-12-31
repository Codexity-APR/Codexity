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

    char **matrix = (char**)malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++) {
#ifdef __cplusplus
        matrix[i] = (char*)malloc(10);
#else
        matrix[i] = (char*)malloc(10 * sizeof(char));
#endif
    }

    while (fgets(line, 100, file)) {
        char **tokens = tokenize(line);

        for (int i = 0; i < 10; i++) {
            matrix[row][i] = tokens[i][0];
        }
        row++;

        free(tokens);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    if (buf) {
        free(buf);
    }

    for (int i = 0; i < 10; i++) {
        free(matrix[i]);
    }
    free(matrix);

    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char **tokens = (char**)malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++) {
#ifdef __cplusplus
        tokens[i] = (char*)malloc(2);
#else
        tokens[i] = (char*)malloc(2 * sizeof(char));
#endif
    }

    char *token = strtok((char*) str, " ");
    int i = 0;
    while (token != NULL) {
        if (i < 10) {
            tokens[i][0] = *token;
            tokens[i][1] = '\0';
            i++;
        }
        token = strtok(NULL, " ");
    }

    return tokens;
}