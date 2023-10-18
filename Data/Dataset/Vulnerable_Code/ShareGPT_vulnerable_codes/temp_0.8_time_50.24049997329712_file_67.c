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
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters)) {
            str[i] = '\0';
            if (token_start != NULL) {
                tokens[count] = strdup(token_start);
                count++;
                token_start = NULL;
            }
        } else if (i == input_len) {
            if (token_start != NULL) {
                tokens[count] = strdup(token_start);
                count++;
            }
        } else if (token_start == NULL) {
            token_start = &str[i];
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "Hello World! This is a sample string.";
    const char* delimiters = " ";
    int max_tokens = 10;
    int token_count = 0;

    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);

    printf("Token Count: %d\n", token_count);
    printf("Tokens:\n");
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}