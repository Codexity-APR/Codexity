List of vulnerabilities detected: 
Error: Null Dereference   pointer `tokens` last assigned on line 27 could be null and is dereferenced at line 28, column 17.
 Example: 
  26.                 count++;
  27.                 tokens = realloc(tokens, sizeof(char*) * count);
  28.                 tokens[count - 1] = strdup(token_start);
                      ^
  29.             }
  30.             token_start = str + i + 1;

Error: Null Dereference   pointer `str` last assigned on line 17 could be null and is dereferenced at line 23, column 26.
 Example: 
  21. 
  22.     for (size_t i = 0; i <= input_len; ++i) {
  23.         if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
                               ^
  24.             str[i] = '\0';
  25.             if (strlen(token_start) > 0) {

 Error type: CWE-401 at line: 27. Error message: Common realloc mistake: 'tokens' nulled but not freed upon failure


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
            str[i] = '\0';
            if (strlen(token_start) > 0) {
                count++;
                tokens = realloc(tokens, sizeof(char*) * count);
                tokens[count - 1] = strdup(token_start);
            }
            token_start = str + i + 1;
        }
    }
    *token_count = count;
    free(str);
    return tokens;
}
int main() {
    const char* input = "Hello,World!Welcome|to Coding";
    const char* delimiters = ",| ";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    printf("Token Count: %d\n", token_count);
    printf("Tokens: ");
    for (int i = 0; i < token_count; ++i) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
    for (int i = 0; i < token_count; ++i) {
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}