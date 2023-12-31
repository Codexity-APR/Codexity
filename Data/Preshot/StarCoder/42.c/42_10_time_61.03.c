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
    if (str == NULL) {
        *token_count = 0;
        return NULL;
    }
    char* token_start = str;
    int count = 0;
    char** tokens = NULL;

    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            str[i] = '\0';
            char** new_tokens = realloc(tokens, sizeof(char*) * (count + 1));
            if (new_tokens == NULL) {
                for (int j = 0; j < count; j++) {
                    free(tokens[j]);
                }
                free(tokens);
                *token_count = 0;
                return NULL;
            }
            tokens = new_tokens;

            tokens[count] = strdup(token_start);
            if (tokens[count] == NULL) {
                for (int j = 0; j < count; j++) {
                    free(tokens[j]);
                }
                free(tokens);
                *token_count = 0;
                return NULL;
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
    if (tokens == NULL) {
        printf("Parsing failed.\n");
        return 1;
    }
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}