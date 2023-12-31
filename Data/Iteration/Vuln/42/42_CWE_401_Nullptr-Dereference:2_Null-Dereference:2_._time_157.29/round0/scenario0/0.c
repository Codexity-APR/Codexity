List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 26 indirectly during the call to `parse_string()`in call to `parse_string()` .
 Example: 
  42.     const char* delimiters = ",! ?";
  43.     int token_count = 0;
  44.     char** tokens = parse_string(input, delimiters, &token_count);
                          ^
  45. 
  46.     for (int i = 0; i < token_count; ++i) {

Error: Null Dereference   pointer `tokens` last assigned on line 25 could be null and is dereferenced at line 26, column 17.
 Example: 
  24.             if (token_start != &str[i]) {
  25.                 tokens = realloc(tokens, (count + 1) * sizeof(char*));
  26.                 tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
                      ^
  27.                 strncpy(tokens[count], token_start, i - (token_start - str));
  28.                 tokens[count][i - (token_start - str)] = '\0';

Error: Null Dereference   pointer `str` last assigned on line 17 could be null and is dereferenced at line 23, column 26.
 Example: 
  21. 
  22.     for (size_t i = 0; i <= input_len; ++i) {
  23.         if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
                               ^
  24.             if (token_start != &str[i]) {
  25.                 tokens = realloc(tokens, (count + 1) * sizeof(char*));

Error: Null Dereference   pointer `*tokens[count]` last assigned on line 26 could be null and is dereferenced by call to `strncpy()` at line 27, column 17.
 Example: 
  25.                 tokens = realloc(tokens, (count + 1) * sizeof(char*));
  26.                 tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
  27.                 strncpy(tokens[count], token_start, i - (token_start - str));
                      ^
  28.                 tokens[count][i - (token_start - str)] = '\0';
  29.                 count++;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 26.
 Example: 
  26.                 tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
  27.                 strncpy(tokens[count], token_start, i - (token_start - str));
  28.                 tokens[count][i - (token_start - str)] = '\0';
                      ^
  29.                 count++;
  30.             }

 Error type: CWE-401 at line: 25. Error message: Common realloc mistake: 'tokens' nulled but not freed upon failure


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
            if (token_start != &str[i]) {
                tokens = realloc(tokens, (count + 1) * sizeof(char*));
                tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
                strncpy(tokens[count], token_start, i - (token_start - str));
                tokens[count][i - (token_start - str)] = '\0';
                count++;
            }
            token_start = &str[i + 1];
        }
    }
    *token_count = count;
    free(str);
    return tokens;
}
int main() {
    const char* input = "Hello,world!How are you doing?";
    const char* delimiters = ",! ?";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}