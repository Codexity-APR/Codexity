#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    char* str = strdup(input);
    char* token;
    int count = 0;
    char** tokens = NULL;

    token = strtok(str, delimiters);
    while (token != NULL) {
        ++count;
        if (count > *token_count) {
            tokens = (char**) realloc(tokens, count * sizeof(char*));
            *token_count = count;
        }
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    free(str);
    return tokens;
}

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
        char** tokens = parse_string(line, " ", &token_count);
        if (tokens == NULL) {
            printf("Failed to parse string: %s\n", line);
            return 1;
        }
        for (int i = 0; i < token_count; ++i) {
            printf("%s ", tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
        printf("\n");
        ++row;
    }

    fclose(file);
    return 0;
}