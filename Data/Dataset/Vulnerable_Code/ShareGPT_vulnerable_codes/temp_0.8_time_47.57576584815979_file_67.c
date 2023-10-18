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

char** parse_string(const char* input, const char* delimiters, int max_tokens, int* token_count) {
    size_t input_len = strlen(input);
    char* str = strdup(input);
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || i == input_len) {
            if (count < max_tokens) {
                size_t token_len = &str[i] - token_start;
                tokens[count] = malloc((token_len + 1) * sizeof(char));
                strncpy(tokens[count], token_start, token_len);
                tokens[count][token_len] = '\0';
                ++count;
            }
            token_start = &str[i + 1];
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "Hello, world! This is a test.";
    const char* delimiters = " ,.!"; // Example delimiters: space, comma, period, exclamation mark
    int max_tokens = 10;
    int token_count;

    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);

    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}