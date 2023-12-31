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
        char** new_tokens = realloc(tokens, sizeof(char*) * count);
        if (new_tokens == NULL) {
            for (int i = 0; i < count - 1; ++i) {
                free(tokens[i]);
            }
            free(tokens);
            free(str);
            return NULL;
        }
        tokens = new_tokens;
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }

    free(str);
    *token_count = count;
    return tokens;
}

int main() {
    FILE* file = fopen("matrix.txt", "r");

    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];
    int row = 0;

    // continue with your code...

    return 0;
}