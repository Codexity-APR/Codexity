#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    memset(tokens, 0, max_tokens * sizeof(char*));
    if (tokens == NULL) {
        return NULL;
    }

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(input[i], delimiters) || i == input_len) {
            str[i] = '\0';
            if (count < max_tokens) {
                tokens[count++] = token_start;
                token_start = &str[i + 1];
            } else {
                free(str);
                return NULL;
            }
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    char input[100];
    const char* delimiters = " .,";
    int max_tokens = 10, token_count = 0;
    printf("Enter the input string: ");
    fgets(input, 100, stdin);
    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);

    if (tokens == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Total tokens: %d\n", token_count);
    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
    }

    free(tokens);
    return 0;
}