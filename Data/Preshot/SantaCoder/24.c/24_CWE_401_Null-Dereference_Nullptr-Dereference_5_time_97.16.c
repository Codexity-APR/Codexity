#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_string(const char* input, const char* delimiters, int* token_count);

int main() {
    FILE *file = fopen("matrix.txt", "r");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0;

    // Read lines from file
    while (fgets(line, sizeof(line), file)) {
        char **tokens = NULL;
        const char *delimiter = " ";
        int token_count = 0;

        tokens = parse_string(line, delimiter, &token_count);

        // Print tokens
        for (int i = 0; i < token_count; i++) {
            printf("%s\n", tokens[i]);
        }

        // Free memory allocated for tokens
        for (int i = 0; i < token_count; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    fclose(file);

    return 0;
}

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    char* str = strdup(input);
    char* token;
    int count = 0;
    char** tokens = NULL;

    token = strtok(str, delimiters);
    while (token != NULL) {
        ++count;
        if (count > token_count[0]) {
            tokens = (char**) realloc(tokens, count * sizeof(char*));
            token_count[0] = count;
        }
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    free(str);
    return tokens;
}