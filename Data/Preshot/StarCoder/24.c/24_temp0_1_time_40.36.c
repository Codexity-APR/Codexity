#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* str, const char* delimiters, int* token_count);

int main() {
    FILE *file = fopen("matrix.txt", "r");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        int token_count = 0;
        char** tokens = tokenize(line, ",", &token_count);

        // Do something with the tokens

        free(tokens);
        ++row;
    }

    fclose(file);
    return 0;
}

char** tokenize(const char* str, const char* delimiters, int* token_count) {
    char* str_copy = strdup(str);
    char* token = strtok(str_copy, delimiters);
    char** tokens = NULL;

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (*token_count + 1));
        if (tokens == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        tokens[*token_count] = strdup(token);
        ++(*token_count);
        token = strtok(NULL, delimiters);
    }

    free(str_copy);
    return tokens;
}