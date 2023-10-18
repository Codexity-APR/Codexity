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
        tokens = (char**)realloc(tokens, count * sizeof(char*));
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }

    *token_count = count;
    free(str);

    return tokens;
}

int main() {
    const char* input = "Hello World,How are you today?";
    const char* delimiters = " ,?";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);

    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}