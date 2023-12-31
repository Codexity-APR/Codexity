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
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            str[i] = '\0';
            if (count < max_tokens) {
                tokens[count] = strdup(token_start);
                token_start = str + i + 1;
                count++;
            } else {
                // Handle the case where there are more tokens than max_tokens
                // You can choose to add an error message or resize the tokens array
                break;
            }
        }
    }

    *token_count = count;
    return tokens;
}

int main() {
    const char* input = "Hello,world,this,is,a,test";
    const char* delimiters = ",";
    int max_tokens = 5;
    int token_count;

    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);

    printf("Token Count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}