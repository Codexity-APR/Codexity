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
        if (is_delimiter(input[i], delimiters) || input[i] == '\0') {
            if (i > 0 && !is_delimiter(input[i-1], delimiters)) {
                // Found a token
                ++count;
                tokens = realloc(tokens, count * sizeof(char*));
                tokens[count - 1] = malloc((i - (token_start - str) + 1) * sizeof(char));
                strncpy(tokens[count - 1], token_start, i - (token_start - str));
                tokens[count - 1][i - (token_start - str)] = '\0';
            }
            token_start = &str[i + 1];
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "This is a sample sentence";
    const char* delimiters = " ";
    int token_count;
    char** tokens = parse_string(input, delimiters, &token_count);

    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    
    free(tokens);
    return 0;
}