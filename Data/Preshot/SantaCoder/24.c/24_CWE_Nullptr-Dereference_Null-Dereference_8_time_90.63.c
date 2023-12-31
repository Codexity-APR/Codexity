#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_string(const char* input, const char* delimiters, size_t* token_count) {
    char* str = strdup(input);
    char* token;
    size_t count = 0;
    char** tokens = NULL;

    token = strtok(str, delimiters);
    while (token != NULL) {
        count++;
        if (count > *token_count) {
            tokens = realloc(tokens, count * sizeof(char*));
            if (tokens == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
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
    size_t token_count = 10; // initial number of tokens
    char** tokens = NULL;
    while (fgets(line, sizeof(line), file)) {
        tokens = parse_string(line, " \t\n", &token_count);
        if (tokens == NULL) {
            printf("Failed to parse line: %s\n", line);
            continue;
        }
        // do something with the tokens
        for (size_t i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
            free(tokens[i]);
        }
        printf("\n");
        free(tokens);
    }

    fclose(file);
    return 0;
}