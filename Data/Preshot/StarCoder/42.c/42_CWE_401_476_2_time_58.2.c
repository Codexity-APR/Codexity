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
        return NULL;
    }
    char* token_start = str;
    int count = 0;
    char** tokens = NULL;

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || i == input_len) {
            str[i] = '\0';
            char* token = strdup(token_start);
            if (!token) {
                for (int j = 0; j < count; j++) {
                    free(tokens[j]);
                }
                free(tokens);
                free(str);
                return NULL;
            }
            tokens = realloc(tokens, sizeof(char*) * (count + 1));
            if (!tokens) {
                free(token);
                for (int j = 0; j < count; j++) {
                    free(tokens[j]);
                }
                free(str);
                return NULL;
            }
            tokens[count] = token;
            count++;
            token_start = str + i + 1;
        }
    }
    *token_count = count;
    free(str);
    return tokens;
}

int main(int argc, char* argv[]) {
    char* input = "This is a test string";
    char* delimiters = " ";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens) {
        for (int i = 0; i < token_count; ++i) {
            printf("%s\n", tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
    } else {
        printf("Error: could not parse string\n");
    }
    return 0;
}