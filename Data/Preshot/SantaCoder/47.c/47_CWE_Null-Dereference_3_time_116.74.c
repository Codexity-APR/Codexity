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
        char c = str[i];
        if (is_delimiter(c, delimiters)) {
            if (count > 0) {
                strncpy(tokens[count - 1], token_start, i - (size_t) token_start);
                tokens[count - 1][i - (size_t) token_start] = '\0';
            }
            token_start = &str[i + 1];
        } else if (i == input_len) {
            if (count >= MAX_TOKENS) {
                return -1;
            }
            strncpy(tokens[count], token_start, i - (size_t) token_start);
            tokens[count][i - (size_t) token_start] = '\0';
            count++;
        } else {
            if (count >= MAX_TOKENS || i - (size_t) token_start == MAX_TOKEN_LENGTH) {
                return -1;
            }
            if (count > 0) {
                strncpy(tokens[count - 1], token_start, i - (size_t) token_start);
                tokens[count - 1][i - (size_t) token_start] = '\0';
            }
            count++;
        }
    }

    free(str);
    return count;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int count = parse_string(argv[1], " \t\n\r\f\v", tokens);

    if (count < 0) {
        printf("Error: Maximum number of tokens exceeded\n");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}