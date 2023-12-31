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

    while (fgets(line, sizeof(line), file)) {
        char** tokens = tokenize(line);
        if (tokens != NULL) {
            // Process tokens here
            // ...
            free(tokens);
        }
        row++;
    }

    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    char* str_copy = strdup(str);
    char* p = strtok(str_copy, " \t\r\n");
    int count = 0;
    char** tokens = NULL;
    while (p) {
        count++;
        tokens = realloc(tokens, count * sizeof(char*));
        tokens[count - 1] = p;
        p = strtok(NULL, " \t\r\n");
    }
    tokens = realloc(tokens, (count + 1) * sizeof(char*));
    tokens[count] = NULL;
    free(str_copy);
    return tokens;
}