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
    if (input == NULL || delimiters == NULL) { // Check for null input or delimiters
        *token_count = 0;
        return NULL;
    }
    size_t input_len = strlen(input);
    char* str = strdup(input);
    if (str == NULL) { // Check for allocation failure
        *token_count = 0;
        return NULL;
    }
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    if (tokens == NULL) { // Check for allocation failure
        free(str);
        *token_count = 0;
        return NULL;
    }

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') { // Check for end of token
            str[i] = '\0';
            if (count == max_tokens) { // Check for too many tokens
                free(str);
                free(tokens);
                *token_count = 0;
                return NULL;
            }
            tokens[count++] = token_start;
            token_start = str + i + 1;
        }
    }
    *token_count = count;
    return tokens;
}

int main(int argc, char* argv[]) {
    char* input = "a,b,c";
    char* delimiters = ",";
    int max_tokens = 10;
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);
    if (tokens == NULL) {
        printf("Error: Unable to parse input.\n");
        return 1;
    }
    printf("token_count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("token %d: %s\n", i, tokens[i]);
    }
    free(tokens);
    return 0;
}