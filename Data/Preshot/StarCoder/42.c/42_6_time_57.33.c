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
    if (!str) {
        return NULL; // return NULL if strdup fails
    }
    char* token_start = str;
    int count = 0;
    char** tokens = NULL;

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || i == input_len) {
            str[i] = '\0';
            char** new_tokens = realloc(tokens, sizeof(char*) * (count + 1));
            if (!new_tokens) {
                for (int j = 0; j < count; ++j) {
                    free(tokens[j]);
                }
                free(tokens);
                return NULL; // return NULL if realloc fails
            }
            tokens = new_tokens;
            tokens[count] = strdup(token_start);
            if (!tokens[count]) {
                for (int j = 0; j < count; ++j) {
                    free(tokens[j]);
                }
                free(tokens);
                return NULL; // return NULL if strdup fails
            }
            count++;
            token_start = str + i + 1;
        }
    }
    free(str);
    *token_count = count;
    return tokens;
}

int main(int argc, char* argv[]) {
    char* input = "This is a test string";
    char* delimiters = " ";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (!tokens) {
        printf("Error: parsing failed.\n");
        return 1;
    }
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
    }
    for (int i = 0; i < token_count; ++i) {
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}