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
    if (str == NULL) {
        return NULL;
    }
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    if (tokens == NULL) {
        free(str);
        return NULL;
    }

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            if (count > 0) {
                tokens[*token_count] = malloc((count + 1) * sizeof(char));
                if (tokens[*token_count] == NULL) {
                    for (int j = 0; j < *token_count; j++) {
                        free(tokens[j]);
                    }
                    free(tokens);
                    free(str);
                    return NULL;
                }
                strncpy(tokens[*token_count], token_start, count);
                tokens[*token_count][count] = '\0';
                *token_count += 1;
                count = 0;
                token_start = str + i + 1;
            } else {
                token_start = str + i + 1;
            }
        } else {
            ++count;
        }
    }

    free(str);
    return tokens;
}