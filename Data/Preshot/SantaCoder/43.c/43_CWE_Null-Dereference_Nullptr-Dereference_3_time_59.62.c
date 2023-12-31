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
        if (str[i] == '\0' || is_delimiter(str[i], delimiters)) {
            if (count > 0) {
                tokens[*token_count] = strndup(token_start, count);
                ++(*token_count);
                if (*token_count == max_tokens) {
                    return tokens;
                }
            }
            count = 0;
            token_start = str + i + 1;
        } else {
            ++count;
        }
    }
    return tokens;
}