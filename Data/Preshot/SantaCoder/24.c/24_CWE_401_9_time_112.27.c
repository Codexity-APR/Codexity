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
        row++;
        char** tokens = tokenize(line);
        if (!tokens) {
            printf("Failed to tokenize line %d\n", row);
            continue;
        }
        // do something with the tokens
        free(tokens);
    }

    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    char* input = strdup(str);
    if (!input) {
        printf("Failed to allocate memory for input string\n");
        return NULL;
    }
    char* delimiters = " \t\n";
    char* token;
    char** tokens = NULL;
    int count = 0;
    int token_count = 0;

    token = strtok(input, delimiters);
    while (token != NULL) {
        count++;
        if (count > token_count) {
            token_count = count;
            tokens = (char**) realloc(tokens, token_count * sizeof(char*));
            if (!tokens) {
                printf("Failed to allocate memory for tokens\n");
                free(input);
                return NULL;
            }
        }
        tokens[count - 1] = strdup(token);
        if (!tokens[count - 1]) {
            printf("Failed to allocate memory for token %d\n", count);
            for (int i = 0; i < count - 1; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(input);
            return NULL;
        }
        token = strtok(NULL, delimiters);
    }
    free(input);
    return tokens;
}