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
    if (!str) {
        return NULL; // Check if strdup fails to allocate memory
    }
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    if (!tokens) {
        free(str); // Free the memory allocated by strdup
        return NULL; // Check if malloc fails to allocate memory
    }

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') { // Check for end of input string too
            if (count > 0) {
                tokens[*token_count] = strndup(token_start, count);
                if (!tokens[*token_count]) {
                    for (int j = 0; j < *token_count; j++) {
                        free(tokens[j]); // Free the memory allocated by strndup
                    }
                    free(tokens); // Free the memory allocated by malloc
                    free(str); // Free the memory allocated by strdup
                    return NULL; // Check if strndup fails to allocate memory
                }
                (*token_count)++;
            }
            count = 0;
            token_start = str + i + 1;
        } else {
            ++count;
        }
    }

    return tokens;
}