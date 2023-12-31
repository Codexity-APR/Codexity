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
    while (fgets(line, 100, file)) {
        int token_count = 0;
        char** tokens = parse_string(line, " ", &token_count);
        if (tokens == NULL) {
            printf("Failed to parse string: %s\n", line);
            return 1;
        }
        // Do something with tokens here
        free(tokens);
    }
    fclose(file);
    return 0;
}

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    char* str = strdup(input);
    if (str == NULL) {
        return NULL;
    }
    char* token;
    int count = 0;
    char** tokens = NULL;

    token = strtok(str, delimiters);
    while (token != NULL) {
        ++count;
        if (count > *token_count) {
            tokens = (char**)realloc(tokens, count * sizeof(char*));
            if (tokens == NULL) {
                free(str);
                return NULL;
            }
            *token_count = count;
        }
        tokens[count - 1] = strdup(token);
        if (tokens[count - 1] == NULL) {
            for (int i = 0; i < count - 1; ++i) {
                free(tokens[i]);
            }
            free(tokens);
            free(str);
            return NULL;
        }
        token = strtok(NULL, delimiters);
    }
    free(str);
    return tokens;
}