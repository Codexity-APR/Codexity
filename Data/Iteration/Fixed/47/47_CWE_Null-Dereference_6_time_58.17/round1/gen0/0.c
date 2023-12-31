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
    if (str == NULL) { // Check if strdup failed
        return -1; // Return an error code
    }
    char* token_start = str;
    int count = 0;
    for (size_t i = 0; i <= input_len; ++i) {
        if (str != NULL && (is_delimiter(str[i], delimiters) || str[i] == '\0')) {
            size_t token_length = &str[i] - token_start;
            strncpy(tokens[count], token_start, token_length);
            tokens[count][token_length] = '\0';
            ++count;
            token_start = &str[i + 1];
        }
    }
    free(str);
    return count;
}

int main() {
    const char* input = "Hello,World,How,Are,You";
    const char* delimiters = ",";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int num_tokens = parse_string(input, delimiters, tokens);
    if (num_tokens == -1) { // Check if parse_string failed
        printf("Failed to parse the string.\n");
        return 1; // Return an error code
    }
    for (int i = 0; i < num_tokens; ++i) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
    }
    return 0;
}