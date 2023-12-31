List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 44 by call to `malloc`, is not freed after the last access at line 50, column 13.
 Example: 
  48.                 free(tokens[j]);
  49.             }
  50.             free(tokens);
                  ^
  51.             return NULL;
  52.         }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 16 by call to `tokenize()`, is not freed after the last access at line 27, column 9.
 Example: 
  25.             free(tokens[i]);
  26.         }
  27.         free(tokens);
              ^
  28.         row++;
  29.     }


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
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            fclose(file); // Close the file before returning
            return 1;
        }
        // Code to process tokens
        // Free memory allocated for tokens
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
    const char* delim = " ";
    int size = 2; // Assuming the maximum number of tokens is 2
    char** tokens = (char**)malloc(size * sizeof(char*));
    if (tokens == NULL) {
        return NULL;
    }
    char* token = strtok((char*)str, delim);
    int i = 0;
    while (token != NULL) {
        tokens[i] = (char*)malloc(strlen(token) + 1);
        if (tokens[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        strcpy(tokens[i], token);
        token = strtok(NULL, delim);
        i++;
    }
    tokens[i] = NULL; // Add NULL terminator to the tokens array
    return tokens;
}