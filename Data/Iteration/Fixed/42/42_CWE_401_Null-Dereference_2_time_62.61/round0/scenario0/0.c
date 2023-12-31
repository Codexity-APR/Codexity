List of vulnerabilities detected: 
Error: Null Dereference   pointer `str` last assigned on line 17 could be null and is dereferenced at line 23, column 26.
 Example: 
  21. 
  22.     for (size_t i = 0; i <= input_len; ++i) {
  23.         if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
                               ^
  24.             if (i > 0 && !is_delimiter(str[i - 1], delimiters)) {
  25.                 str[i] = '\0';

 Error type: CWE-401 at line: 26. Error message: Common realloc mistake: 'tokens' nulled but not freed upon failure


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
    char* token_start = str;
    int count = 0;
    char** tokens = NULL;
    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            if (i > 0 && !is_delimiter(str[i - 1], delimiters)) {
                str[i] = '\0';
                tokens = realloc(tokens, (count + 1) * sizeof(char*));
                tokens[count] = strdup(token_start);
                token_start = &(str[i + 1]);
                count++;
            }
        }
    }
    *token_count = count;
    free(str);
    return tokens;
}
int main() {
    const char* input = "Hello, World! This is a test.";
    const char* delimiters = " ,.!";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    printf("Token Count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}