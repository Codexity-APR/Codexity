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
        ++count;
        if (count > *token_count) {
            tokens = realloc(tokens, count * sizeof(char*));
            if (tokens == NULL) {
                free(str);
                return NULL;
            }
            *token_count = count;
        }
        tokens[count - 1] = strdup(token);
        if (tokens[count - 1] == NULL) {
            free(str);
            return NULL;
        }
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
    size_t row = 0;
    while (fgets(line, sizeof(line), file)) {
        size_t count = 0;
        char** tokens = parse_string(line, " \t\n", &count);
        if (tokens == NULL) {
            printf("Failed to parse string: %s\n", line);
            fclose(file);
            return 1;
        }
        for (size_t i = 0; i < count; ++i) {
            printf("%s ", tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
        ++row;
    }
    fclose(file);
    return 0;
}