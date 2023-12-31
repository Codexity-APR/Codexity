#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

bool is_delimiter(char c, const char* delimiters) {
    for (size_t i = 0; i < strlen(delimiters); ++i) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

int parse_string(const char* input, const char* delimiters, char tokens[][MAX_TOKEN_LENGTH]) {
    size_t input_len = strlen(input);
    char* str = strdup(input);
    char* token_start = str;
    int count = 0;

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(input[i], delimiters) || input[i] == '\0') {
            size_t token_length = &str[i] - token_start;
            strncpy(tokens[count], token_start, token_length);
            tokens[count][token_length] = '\0';
            token_start = &str[i+1];
            count++;
        }
    }

    free(str);

    return count;
}

int main() {
    const char* input = "Hello, world! This is a test string.";
    const char* delimiters = ",. ";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = parse_string(input, delimiters, tokens);

    printf("Token count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i+1, tokens[i]);
    }

    return 0;
}