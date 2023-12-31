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
        if (is_delimiter(str[i], delimiters)) {
            if (count > 0) {
                if (tokens == NULL) {
                    tokens = (char**) malloc(sizeof(char*) * (input_len + 1));
                }
                tokens[token_count[0]] = (char*) malloc(sizeof(char) * (count + 1));
                memcpy(tokens[token_count[0]], token_start, count);
                tokens[token_count[0]][count] = '\0';
                token_count[0]++;
                count = 0;
            }
            token_start = str + i + 1;
        } else {
            count++;
        }
    }

    if (token_count[0] == 0 && count > 0) {
        if (tokens == NULL) {
            tokens = (char**) malloc(sizeof(char*) * (input_len + 1));
        }
        tokens[token_count[0]] = (char*) malloc(sizeof(char) * (count + 1));
        memcpy(tokens[token_count[0]], token_start, count);
        tokens[token_count[0]][count] = '\0';
        token_count[0]++;
    }

    free(str);

    return tokens;
}

int main() {
    char* input = "Hello, world! This is a test.";
    char* delimiters = " ,.!";

    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}