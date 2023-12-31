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
            if (count > 0) {
                char* token = (char*) malloc(count + 1);
                memcpy(token, token_start, count);
                token[count] = '\0';
                if (tokens == NULL) {
                    tokens = (char**) malloc(sizeof(char*));
                } else {
                    tokens = (char**) realloc(tokens, (*token_count + 1) * sizeof(char*));
                }
                tokens[*token_count] = token;
                *token_count += 1;
            }
            count = 0;
            token_start = str + i + 1;
        } else {
            count++;
        }
    }

    return tokens;
}

int main() {
    char* input = "Hello, world! How are you today?";
    char* delimiters = " ,!";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens) {
        for (int i = 0; i < token_count; ++i) {
            printf("%s\n", tokens[i]);
        }
    }
    return 0;
}