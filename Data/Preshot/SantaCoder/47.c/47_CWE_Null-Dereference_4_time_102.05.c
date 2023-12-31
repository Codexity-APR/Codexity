#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

bool is_delimiter(char c, const char* delimiters) {
    for (size_t i = 0; i < strlen(delimiters); ++i) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

int parse_string(const char* input, const char* delimiters, char tokens[][MAX_TOKEN_LENGTH]) {
    size_t input_len = strlen(input);
    char* str = strdup(input);
    char* token_start = str;
    int count = 0;

    for (size_t i = 0; i <= input_len; ++i) {
        char c = str[i];
        if (is_delimiter(c, delimiters)) {
            if (count > 0) {
                tokens[count-1][strlen(token_start)-1] = '\0';
            }
            str[i] = '\0';
            strcpy(tokens[count], token_start);
            ++count;
            token_start = &str[i+1];
        } else {
            if (count == MAX_TOKENS) {
                return -1;
            }
        }
    }

    free(str);

    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: no input string specified.\n");
        return -1;
    }

    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int num_tokens = parse_string(argv[1], " \t\n\r\f\v", tokens);
    if (num_tokens < 0) {
        printf("Error: exceeded maximum number of tokens.\n");
        return -1;
    }

    for (int i = 0; i < num_tokens; ++i) {
        printf("Token %d: %s\n", i+1, tokens[i]);
    }

    return 0;
}