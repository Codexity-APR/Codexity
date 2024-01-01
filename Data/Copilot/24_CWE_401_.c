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
        tokens = realloc(tokens, count * sizeof(char*));
        tokens[count - 1] = token;
        token = strtok(NULL, delimiters);
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "This is a test string";
    const char* delimiters = " ";
    int token_count;
    char** tokens = parse_string(input, delimiters, &token_count);

    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
    }

    free(tokens);
    return 0;
}
