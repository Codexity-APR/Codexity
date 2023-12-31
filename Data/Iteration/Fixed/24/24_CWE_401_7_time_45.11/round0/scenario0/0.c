List of vulnerabilities detected: 
Error: Null Dereference   pointer `tokens` last assigned on line 14 could be null and is dereferenced at line 15, column 9.
 Example: 
  13.         ++count;
  14.         tokens = (char**)realloc(tokens, count * sizeof(char*));
  15.         tokens[count-1] = strdup(token);
              ^
  16.         token = strtok(NULL, delimiters);
  17.     }

 Error type: CWE-401 at line: 14. Error message: Common realloc mistake: 'tokens' nulled but not freed upon failure


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** parse_string(const char* input, const char* delimiters, int* token_count) {
    char* str = strdup(input);
    char* token;
    int count = 0;
    char** tokens = NULL;
    token = strtok(str, delimiters);
    while (token != NULL) {
        ++count;
        tokens = (char**)realloc(tokens, count * sizeof(char*));
        tokens[count-1] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    *token_count = count;
    free(str);
    return tokens;
}
int main() {
    const char* input = "Hello,World,How,Are,You";
    const char* delimiters = ",";
    int token_count;
    char** tokens = parse_string(input, delimiters, &token_count);
    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}