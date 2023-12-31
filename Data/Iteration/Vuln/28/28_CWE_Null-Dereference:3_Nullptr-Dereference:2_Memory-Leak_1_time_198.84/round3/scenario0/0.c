List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 58 by call to `malloc`, is not freed after the last access at line 63, column 13.
 Example: 
  61.                 free(tokens[i]);
  62.             }
  63.             free(tokens);
                  ^
  64.             free(strCopy);
  65.             return NULL;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 17 by call to `tokenize()`, is not freed after the last access at line 33, column 9.
 Example: 
  31.             free(tokens[i]);
  32.         }
  33.         free(tokens);
              ^
  34.         row++;
  35.     }


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
    while (fgets(line, sizeof(line), file)) {
        // Tokenize each line
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            fclose(file);
            return 1;
        }
        // Process the tokens
        for (int i = 0; tokens[i] != NULL; i++) {
            // Do something with the token
            printf("%s ", tokens[i]);
        }
        printf("\n");
        // Free the memory allocated for tokens
        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
        row++;
    }
    fclose(file);
    return 0;
}
char** tokenize(const char* str) {
    const char delimiter[2] = " ";
    char* token;
    // Allocate memory for tokens array
    char** tokens = malloc(sizeof(char*) * 100);
    if (tokens == NULL) {
        return NULL;
    }
    int tokenCount = 0;
    // Tokenize the string
    char* strCopy = strdup(str);
    if (strCopy == NULL) {
        free(tokens);
        return NULL;
    }
    token = strtok(strCopy, delimiter);
    while (token != NULL) {
        // Allocate memory for each token
        tokens[tokenCount] = malloc(strlen(token) + 1);
        if (tokens[tokenCount] == NULL) {
            for (int i = 0; i < tokenCount; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(strCopy);
            return NULL;
        }
        strcpy(tokens[tokenCount], token);
        tokenCount++;
        token = strtok(NULL, delimiter);
    }
    tokens[tokenCount] = NULL;
    free(strCopy);
    return tokens;
}