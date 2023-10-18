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
            int token_len = str + i - token_start;
            if (token_len > 0) {
                char* token = malloc((token_len + 1) * sizeof(char));
                strncpy(token, token_start, token_len);
                token[token_len] = '\0';

                tokens = realloc(tokens, (count + 1) * sizeof(char*));
                tokens[count] = token;
                count++;
            }

            token_start = str + i + 1;
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "Hello, World! This is a test.";
    const char* delimiters = " ,.!";

    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);

    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}