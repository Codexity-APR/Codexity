#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* str, const char* delimiters, int* token_count);

int main() {
    FILE* file = fopen("matrix.txt", "r");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0;

    // Read each line from the file and tokenize it
    while (fgets(line, sizeof(line), file)) {
        int token_count = 0;
        char** tokens = tokenize(line, " ,\t\n", &token_count);

        // Process the tokens
        for (int i = 0; i < token_count; i++) {
            printf("Token %d: %s\n", i, tokens[i]);
        }

        // Free the memory allocated for tokens
        for (int i = 0; i < token_count; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    // Close the file
    fclose(file);
    return 0;
}

char** tokenize(const char* str, const char* delimiters, int* token_count) {
    char* str_copy = strdup(str);
    if (str_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    char* token = strtok(str_copy, delimiters);
    char** tokens = NULL;

    while (token != NULL) {
        (*token_count)++;
        tokens = realloc(tokens, sizeof(char*) * (*token_count));
        if (tokens == NULL) {
            perror("realloc");
            free(str_copy);
            return NULL;
        }
        tokens[*token_count - 1] = strdup(token);
        if (tokens[*token_count - 1] == NULL) {
            perror("strdup");
            free(tokens);
            free(str_copy);
            return NULL;
        }
        token = strtok(NULL, delimiters);
    }

    free(str_copy);
    return tokens;
}