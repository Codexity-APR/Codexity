List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 36 indirectly during the call to `parse_string()`in call to `parse_string()` .
 Example: 
  51.     const char* delimiters = ",!";
  52.     int token_count = 0;
  53.     char** tokens = parse_string(input, delimiters, &token_count);
                          ^
  54. 
  55.     if (tokens == NULL) {

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 53 by call to `parse_string()`, is not freed after the last access at line 65, column 5.
 Example: 
  63.         free(tokens[i]);
  64.     }
  65.     free(tokens);
          ^
  66. 
  67.     return 0;

Error: Null Dereference   pointer `*tokens[count]` last assigned on line 36 could be null and is dereferenced by call to `strncpy()` at line 37, column 17.
 Example: 
  35.                 tokens = temp;
  36.                 tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
  37.                 strncpy(tokens[count], token_start, i - (token_start - str));
                      ^
  38.                 tokens[count][i - (token_start - str)] = '\0';
  39.                 ++count;


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
        if (is_delimiter(input[i], delimiters) || input[i] == '\0') {
            if (token_start != &(str[i])) {
                char** temp = realloc(tokens, (count + 1) * sizeof(char*));
                if (temp == NULL) {
                    // Handle realloc failure
                    for (int j = 0; j < count; ++j) {
                        free(tokens[j]);
                    }
                    free(tokens);
                    *token_count = 0;
                    return NULL;
                }
                tokens = temp;
                tokens[count] = malloc((i - (token_start - str) + 1) * sizeof(char));
                strncpy(tokens[count], token_start, i - (token_start - str));
                tokens[count][i - (token_start - str)] = '\0';
                ++count;
            }
            token_start = &(str[i + 1]);
        }
    }
    *token_count = count;
    return tokens;
}
int main() {
    const char* input = "Hello,world!This,is,a,test";
    const char* delimiters = ",!";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens == NULL) {
        printf("Failed to parse string.\n");
        return 1;
    }
    printf("Token Count: %d\n", token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}