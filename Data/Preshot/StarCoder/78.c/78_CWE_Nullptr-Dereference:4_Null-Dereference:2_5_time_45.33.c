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
        if (is_delimiter(input[i], delimiters) || i == input_len) {
            if (token_start != &str[i]) {
                char* token = malloc((i - (token_start - str) + 1) * sizeof(char));
                strncpy(token, token_start, i - (token_start - str));
                token[i - (token_start - str)] = '\0';
                tokens[count++] = token;
                token_start = &str[i + 1];
            } else {
                token_start = &str[i + 1];
            }
        }
        if (count == max_tokens) {
            break;
        }
    }
    *token_count = count;
    return tokens;
}

int main() {
    char input[] = "This is a test string. It will be parsed into tokens.";
    char delimiters[] = " .";
    int max_tokens = 10;
    int token_count;
    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);

    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}