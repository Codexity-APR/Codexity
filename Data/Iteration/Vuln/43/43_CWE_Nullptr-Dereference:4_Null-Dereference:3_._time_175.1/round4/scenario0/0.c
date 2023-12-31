List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 64 by call to `parse_string()`, is not freed after the last access at line 74, column 5.
 Example: 
  72.         free(tokens[i]);
  73.     }
  74.     free(tokens); // Free the dynamically allocated memory for 'tokens'
          ^
  75.     return 0;
  76. }


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
    if (str == NULL) {
        *token_count = 0;
        return NULL;
    }
    char* token_start = str;
    int count = 0;
    char** tokens = malloc(max_tokens * sizeof(char*));
    if (tokens == NULL) {
        free(str);
        *token_count = 0;
        return NULL;
    }
    for (size_t i = 0; i <= input_len; ++i) {
        if (is_delimiter(str[i], delimiters) || str[i] == '\0') {
            if (token_start != &str[i]) {
                size_t token_len = &str[i] - token_start;
                tokens[count] = malloc((token_len + 1) * sizeof(char));
                if (tokens[count] == NULL) {
                    for (int j = 0; j < count; ++j) {
                        free(tokens[j]);
                    }
                    free(tokens);
                    free(str);
                    *token_count = 0;
                    return NULL;
                }
                strncpy(tokens[count], token_start, token_len);
                tokens[count][token_len] = '\0';
                count++;
                if (count == max_tokens) {
                    break;
                }
            }
            token_start = &str[i + 1];
        }
    }
    *token_count = count;
    free(str); // Free the dynamically allocated memory for 'str'
    return tokens;
}
int main() {
    const char* input = "Hello, World! How are you?";
    const char* delimiters = " ,!?";
    int max_tokens = 10;
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, max_tokens, &token_count);
    if (tokens == NULL) {
        printf("Error occurred while parsing the string.\n");
        return 1;
    }
    printf("Tokens:\n");
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens); // Free the dynamically allocated memory for 'tokens'
    return 0;
}