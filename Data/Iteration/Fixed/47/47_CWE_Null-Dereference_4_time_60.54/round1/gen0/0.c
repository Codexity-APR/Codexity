#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // Added for NULL definition
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
    if (str == NULL) { // Added null check
        return 0;
    }
    char* token_start = str;
    int count = 0;
    for (size_t i = 0; i <= input_len; ++i) {
        if (str != NULL && (is_delimiter(str[i], delimiters) || str[i] == '\0')) { // Added null check
            if (i > 0 && !is_delimiter(str[i - 1], delimiters)) {
                strncpy(tokens[count], token_start, i - (token_start - str));
                tokens[count][i - (token_start - str)] = '\0';
                ++count;
            }
            token_start = &str[i + 1];
        }
    }
    free(str);
    return count;
}

int main() {
    const char* input = "Hello,World!How are you today?";
    const char* delimiters = ",! ";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = parse_string(input, delimiters, tokens);
    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
    }
    return 0;
}