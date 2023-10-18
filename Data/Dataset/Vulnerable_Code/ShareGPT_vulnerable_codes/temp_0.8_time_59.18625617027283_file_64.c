#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_delimiter(char c, const char* delimiters) {
    for (size_t i = 0; i < strlen(delimiters); ++i) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    size_t input_len = strlen(input);
    char* str = strdup(input);
    char* token_start = str;
    int count = 0;
    char** tokens = NULL;

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            str[i] = '\0';
            count++;
            tokens = realloc(tokens, count * sizeof(char*));
            tokens[count - 1] = token_start;
            token_start = &str[i + 1];
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "Hello, World! This is a sample string.";
    const char* delimiters = " ,.!"; // Delimiters: space, comma, period, exclamation mark

    int token_count;
    char** tokens = parse_string(input, delimiters, &token_count);

    printf("Token count: %d\n", token_count);
    printf("Tokens: ");
    for (int i = 0; i < token_count; ++i) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    free(tokens);

    return 0;
}