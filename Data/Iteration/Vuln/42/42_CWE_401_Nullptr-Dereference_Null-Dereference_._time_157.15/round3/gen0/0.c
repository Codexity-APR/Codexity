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
            if (token_start != &(str[i])) {
                char** temp = realloc(tokens, (count + 1) * sizeof(char*));
                if (temp == NULL) {
                    // Handle realloc failure
                    for (int j = 0; j < count; ++j) {
                        free(tokens[j]);
                    }
                    free(tokens);
                    *token_count = 0;
                    free(str); // Free the allocated memory for str
                    return NULL;
                }
                tokens = temp;
                tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
                if (tokens[count] == NULL) {
                    // Handle malloc failure
                    for (int j = 0; j < count; ++j) {
                        free(tokens[j]);
                    }
                    free(tokens);
                    *token_count = 0;
                    free(str); // Free the allocated memory for str
                    return NULL;
                }
                strncpy(tokens[count], token_start, i - (token_start - str));
                tokens[count][i - (token_start - str)] = '\0';
                ++count;
            }
            token_start = &(str[i + 1]);
        }
    }
    *token_count = count;
    free(str); // Free the allocated memory for str
    return tokens;
}

int main() {
    const char* input = "Hello,world!This,is,a,test";
    const char* delimiters = ",!";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens == NULL) {
        printf("Failed to parse string.\n");
        return 1;
    }
    printf("Token Count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}