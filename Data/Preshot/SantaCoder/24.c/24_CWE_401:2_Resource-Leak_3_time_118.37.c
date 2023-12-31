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
    char** tokens = NULL;
    int count = 0;
    int token_count = 0;

    while (fgets(line, sizeof line, file)) {
        tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line: %s\n", line);
            return 1;
        }
        for (count = 0; tokens[count] != NULL; ++count) {
            printf("Token %d: %s\n", count, tokens[count]);
        }
        token_count = count;
        free(tokens);
    }

    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    char* str_copy = strdup(str);
    if (str_copy == NULL) {
        return NULL;
    }

    const char* delimiters = " ,;:\n\t";
    char* token = strtok(str_copy, delimiters);
    char** tokens = NULL;
    int count = 0;

    while (token != NULL) {
        ++count;
        tokens = (char**) realloc(tokens, count * sizeof(char*));
        if (tokens == NULL) {
            free(str_copy);
            return NULL;
        }
        tokens[count - 1] = strdup(token);
        if (tokens[count - 1] == NULL) {
            free(tokens);
            free(str_copy);
            return NULL;
        }
        token = strtok(NULL, delimiters);
    }

    free(str_copy);
    tokens = (char**) realloc(tokens, (count + 1) * sizeof(char*));
    if (tokens == NULL) {
        return NULL;
    }

    tokens[count] = NULL;

    return tokens;
}