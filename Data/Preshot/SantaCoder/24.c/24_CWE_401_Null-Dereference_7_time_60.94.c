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
            *token_count = count;
            tokens = (char**)realloc(tokens, count * sizeof(char*));
        }
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    free(str);
    return tokens;
}

int main() {
    char* input = "1234567890";
    char* delimiters = " ";
    size_t token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens == NULL) {
        printf("Failed to parse string: %s\n", input);
        return 1;
    }
    for (size_t count = 0; count < token_count; ++count) {
        printf("%s ", tokens[count]);
    }
    free(tokens);
    return 0;
}