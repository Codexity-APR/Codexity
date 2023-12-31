#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
        if (is_delimiter(str[i], delimiters)) {
            str[i] = '\0';

            if (i - token_start > 0) {
                strncpy(tokens[count], token_start, i - token_start);
                tokens[count][i - token_start] = '\0';
                count++;   
            }

            token_start = str + i + 1;
        }
    }

    free(str);
    return count;
}

int main(int argc, char* argv[]) {
    char input[MAX_TOKENS][MAX_TOKEN_LENGTH];
    char delimiters[] = ",.?!";
    int num_tokens = parse_string(argv[1], delimiters, input);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", input[i]);
    }

    return 0;
}