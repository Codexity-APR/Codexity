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
    if (input == NULL || delimiters == NULL || token_count == NULL) {
        return NULL; // handle invalid input
    }
    size_t input_len = strlen(input);
    char* str = strdup(input);
    if (str == NULL) {
        return NULL; // handle memory allocation failure
    }
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    if (tokens == NULL) {
        free(str); // free previously allocated memory
        return NULL; // handle memory allocation failure
    }

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            str[i] = '\0';
            if (count < max_tokens) {
                tokens[count++] = token_start;
                token_start = str + i + 1;
            }
            else {
                free(str); // free previously allocated memory
                free(tokens); // free previously allocated memory
                return NULL; // handle max_tokens limit reached
            }
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
        printf("Unable to parse the input string.\n");
        return 1;
    }
    printf("token_count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("token %d: %s\n", i, tokens[i]);
    }
    free(tokens); // free memory allocated by parse_string function
    return 0;
}