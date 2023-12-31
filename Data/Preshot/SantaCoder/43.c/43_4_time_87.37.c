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

    if (str == NULL || tokens == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            if (count > 0) {
                // Allocate memory for the token
                tokens[token_count[0]] = malloc((count + 1) * sizeof(char));
                if (tokens[token_count[0]] == NULL) {
                    perror("Memory allocation error");
                    exit(EXIT_FAILURE);
                }

                // Copy the token into the token array
                strncpy(tokens[token_count[0]], token_start, count);
                tokens[token_count[0]][count] = '\0';
                ++token_count[0];

                // Check if we have reached the maximum number of tokens
                if (token_count[0] == max_tokens) {
                    return tokens;
                }
            }
            count = 0;
            token_start = &str[i + 1];
        } else {
            ++count;
        }
    }

    return tokens;
}