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
        char** temp = realloc(tokens, sizeof(char*) * count);
        if (temp == NULL) {
            // Handle realloc failure
            for (int i = 0; i < count - 1; ++i) {
                free(tokens[i]);
            }
            free(tokens);
            free(str);
            return NULL;
        }
        tokens = temp;
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    *token_count = count;
    free(str);
    return tokens;
}

int main() {
    const char* input = "Hello, World! How are you today?";
    const char* delimiters = " ,!";
    int token_count;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens == NULL) {
        printf("Failed to allocate memory for tokens.\n");
        return 1;
    }
    printf("Token count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}