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
    if (str == NULL) {
        return 0; // Handle memory allocation failure
    }
    char* token_start = str;
    int count = 0;
    for (size_t i = 0; i <= input_len; ++i) {
        if (str != NULL && (is_delimiter(str[i], delimiters) || str[i] == '\0')) {
            if (token_start != &str[i]) {
                strncpy(tokens[count], token_start, &str[i] - token_start);
                tokens[count][&str[i] - token_start] = '\0';
                count++;
            }
            token_start = &str[i + 1];
        }
    }
    free(str); // Free the allocated memory
    return count;
}

int main() {
    const char* input = "Hello, world! This is a sample string.";
    const char* delimiters = " ,.!";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = parse_string(input, delimiters, tokens);
    printf("Token Count: %d\n", token_count);
    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
    }
    return 0;
}