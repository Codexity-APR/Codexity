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
    if (str == NULL) {
        *token_count = 0;
        return NULL;
    }
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    if (tokens == NULL) {
        *token_count = 0;
        free(str);
        return NULL;
    }
    for (size_t i = 0; i <= input_len; ++i) {
        if (str != NULL && (is_delimiter(str[i], delimiters) || str[i] == '\0')) {
            if (count < max_tokens) {
                size_t token_len = &str[i] - token_start;
                tokens[count] = malloc((token_len + 1) * sizeof(char));
                if (tokens[count] == NULL) {
                    // Handle allocation failure
                    for (int j = 0; j < count; ++j) {
                        free(tokens[j]);
                    }
                    free(tokens);
                    *token_count = 0;
                    free(str);
                    return NULL;
                }
                strncpy(tokens[count], token_start, token_len);
                tokens[count][token_len] = '\0';
                token_start = &str[i + 1];
                count++;
            } else {
                break;
            }
        }
    }
    *token_count = count;
    free(str);
    return tokens;
}

int main() {
    const char* input = "Hello, World! I am a coding editor.";
    const char* delimiters = " ,.!";
    int max_tokens = 10;
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);
    if (tokens != NULL) {
        for (int i = 0; i < token_count; ++i) {
            printf("Token %d: %s\n", i+1, tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
    } else {
        printf("Failed to parse string.\n");
    }
    return 0;
}