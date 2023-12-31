List of vulnerabilities detected: 
Error: Null Dereference   pointer `tokens` last assigned on line 20 could be null and is dereferenced at line 31, column 13.
 Example: 
  29.             strncpy(token, token_start, token_length);
  30.             token[token_length] = '\0';
  31.             tokens[count++] = token;
                  ^
  32.             token_start = &str[i + 1];
  33.         }

Error: Null Dereference   pointer `token` last assigned on line 28 could be null and is dereferenced by call to `strncpy()` at line 29, column 13.
 Example: 
  27.             size_t token_length = &str[i] - token_start;
  28.             char* token = malloc((token_length + 1) * sizeof(char));
  29.             strncpy(token, token_start, token_length);
                  ^
  30.             token[token_length] = '\0';
  31.             tokens[count++] = token;

Error: Null Dereference   pointer `str` last assigned on line 17 could be null and is dereferenced at line 23, column 26.
 Example: 
  21. 
  22.     for (size_t i = 0; i <= input_len; ++i) {
  23.         if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
                               ^
  24.             if (count >= max_tokens) {
  25.                 break;


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
            if (count >= max_tokens) {
                break;
            }
            size_t token_length = &str[i] - token_start;
            char* token = malloc((token_length + 1) * sizeof(char));
            strncpy(token, token_start, token_length);
            token[token_length] = '\0';
            tokens[count++] = token;
            token_start = &str[i + 1];
        }
    }
    *token_count = count;
    return tokens;
}
int main() {
    const char* input = "Hello World, How are you?";
    const char* delimiters = " ,?";
    int max_tokens = 10;
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);
    printf("Token Count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i+1, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}