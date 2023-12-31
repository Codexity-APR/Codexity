List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 44 by call to `malloc`, is not freed after the last access at line 73, column 13.
 Example: 
  71.         // Resize the tokens array
  72.         char** new_tokens = realloc(tokens, (i + 2) * sizeof(char*));
  73.         if (new_tokens == NULL) {
                  ^
  74.             free(new_token);
  75.             for (int j = 0; j < i; j++) {

Error: Resource Leak   resource of type `__sFILE` acquired by call to `fopen()` at line 8, column 18 is not released after line 20, column 13.
 Example: 
  18.         char** tokens = tokenize(line);
  19.         if (tokens == NULL) {
  20.             printf("Failed to tokenize line\n");
                  ^
  21.             return 1;
  22.         }

Error: Buffer Overrun L3   Offset: [1, 99] Size: [2, 100] by call to `tokenize`.
 Example: 
  16.     while (fgets(line, sizeof(line), file)) {
  17.         // Tokenize the line
  18.         char** tokens = tokenize(line);
                              ^
  19.         if (tokens == NULL) {
  20.             printf("Failed to tokenize line\n");


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** tokenize(const char* str);
int main() {
    FILE *file = fopen("matrix.txt", "r");
    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }
    char line[100];
    int row = 0;
    // Read file line by line
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            return 1;
        }
        // Process each token
        for (int i = 0; tokens[i] != NULL; i++) {
            // Do something with the token, e.g. print it
            printf("%s ", tokens[i]);
            // Free memory allocated for the token
            free(tokens[i]);
        }
        // Free memory allocated for the tokens array
        free(tokens);
        // Increment the row count
        row++;
    }
    // Close the file
    fclose(file);
    return 0;
}
char** tokenize(const char* str) {
    const char* delimiter = " ";
    char* token;
    // Allocate memory for tokens array
    char** tokens = malloc(sizeof(char*));
    if (tokens == NULL) {
        return NULL;
    }
    // Copy the input string
    char* input = malloc(strlen(str) + 1);
    if (input == NULL) {
        free(tokens);
        return NULL;
    }
    strcpy(input, str);
    // Tokenize the string
    token = strtok(input, delimiter);
    int i = 0;
    while (token != NULL) {
        // Allocate memory for the token
        char* new_token = malloc(strlen(token) + 1);
        if (new_token == NULL) {
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            free(input);
            return NULL;
        }
        // Copy the token
        strcpy(new_token, token);
        // Resize the tokens array
        char** new_tokens = realloc(tokens, (i + 2) * sizeof(char*));
        if (new_tokens == NULL) {
            free(new_token);
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            free(input);
            return NULL;
        }
        tokens = new_tokens;
        tokens[i] = new_token;
        tokens[i + 1] = NULL;
        // Get the next token
        token = strtok(NULL, delimiter);
        // Increment the token count
        i++;
    }
    // Free memory allocated for input string
    free(input);
    return tokens;
}