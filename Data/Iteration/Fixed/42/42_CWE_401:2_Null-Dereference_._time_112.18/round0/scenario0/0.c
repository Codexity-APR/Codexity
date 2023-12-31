List of vulnerabilities detected: 
Error: Null Dereference   pointer `tokens` last assigned on line 35 could be null and is dereferenced at line 36, column 17.
 Example: 
  34.                 count++;
  35.                 tokens = (char**)realloc(tokens, count * sizeof(char*));
  36.                 tokens[count - 1] = strdup(token_start);
                      ^
  37.             }
  38.         } else if (token_start == NULL) {

Error: Null Dereference   pointer `tokens` last assigned on line 28 could be null and is dereferenced at line 29, column 17.
 Example: 
  27.                 count++;
  28.                 tokens = (char**)realloc(tokens, count * sizeof(char*));
  29.                 tokens[count - 1] = strdup(token_start);
                      ^
  30.                 token_start = NULL;
  31.             }

Error: Null Dereference   pointer `str` last assigned on line 17 could be null and is dereferenced at line 23, column 26.
 Example: 
  21. 
  22.     for (size_t i = 0; i <= input_len; ++i) {
  23.         if (is_delimiter(str[i], delimiters)) {
                               ^
  24.             str[i] = '\0';
  25.

 Error type: CWE-401 at line: 28. Error message: Common realloc mistake: 'tokens' nulled but not freed upon failure

 Error type: CWE-401 at line: 35. Error message: Common realloc mistake: 'tokens' nulled but not freed upon failure


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
        if (is_delimiter(str[i], delimiters)) {
            str[i] = '\0';
            if (token_start != NULL) {
                count++;
                tokens = (char**)realloc(tokens, count * sizeof(char*));
                tokens[count - 1] = strdup(token_start);
                token_start = NULL;
            }
        } else if (str[i] == '\0') {
            if (token_start != NULL) {
                count++;
                tokens = (char**)realloc(tokens, count * sizeof(char*));
                tokens[count - 1] = strdup(token_start);
            }
        } else if (token_start == NULL) {
            token_start = &str[i];
        }
    }
    *token_count = count;
    return tokens;
}
int main() {
    const char* input = "Hello World! This is a test string.";
    const char* delimiters = " ";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    printf("Token count: %d\n", token_count);
    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}