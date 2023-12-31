List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 50 by call to `malloc`, is not freed after the last access at line 56, column 13.
 Example: 
  54.                 free(tokens[j]);
  55.             }
  56.             free(tokens);
                  ^
  57.             return NULL;
  58.         }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 18 by call to `tokenize()`, is not freed after the last access at line 30, column 9.
 Example: 
  28.             free(tokens[i]);
  29.         }
  30.         free(tokens);
              ^
  31.         row++;
  32.     }


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
    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line into an array of strings
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            fclose(file);
            return 1;
        }
        // Process the tokens here
        // Free the memory allocated for tokens
        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
        row++;
    }
    // Close the file
    fclose(file);
    return 0;
}
// Tokenize a string and return an array of strings
char** tokenize(const char* str) {
    const char* delimiters = " \t\n"; // space, tab, newline
    char* token = strtok((char*)str, delimiters);
    // Allocate memory for storing tokens
    char** tokens = (char**)malloc(sizeof(char*) * 10);
    if (tokens == NULL) {
        return NULL;
    }
    int i = 0;
    // Store each token in the array
    while (token != NULL) {
        tokens[i] = (char*)malloc(strlen(token) + 1);
        if (tokens[i] == NULL) {
            // Handle memory allocation failure
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, delimiters);
    }
    tokens[i] = NULL; // Set the last element to NULL to mark the end of the array
    return tokens;
}