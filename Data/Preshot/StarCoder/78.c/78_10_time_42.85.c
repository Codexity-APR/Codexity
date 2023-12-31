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
    if (tokens == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    memset(tokens, 0, max_tokens * sizeof(char*)); //initialize all elements of array to NULL

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(input[i], delimiters) || input[i] == '\0') {
            if (token_start == &str[i]) { //ignoring consecutive delimiters
                token_start++;
                continue;
            }
            char* token = malloc((i - (token_start - str) + 1) * sizeof(char));
            if (token == NULL)
            {
                printf("Error: Memory allocation failed!\n");
                exit(1);
            }
            strncpy(token, token_start, i - (token_start - str));
            token[i - (token_start - str)] = '\0';
            tokens[count] = token;
            count++;
            token_start = &str[i + 1];

            if (count == max_tokens) {
                break;
            }
        }
    }
    *token_count = count;
    return tokens;
}