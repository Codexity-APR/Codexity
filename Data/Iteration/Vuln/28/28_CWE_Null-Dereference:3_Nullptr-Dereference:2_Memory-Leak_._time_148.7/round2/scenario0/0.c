List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 45 by call to `malloc`, is not freed after the last access at line 51, column 13.
 Example: 
  49.                 free(tokens[j]);
  50.             }
  51.             free(tokens);
                  ^
  52.             return NULL;
  53.         }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 17 by call to `tokenize()`, is not freed after the last access at line 29, column 9.
 Example: 
  27.             free(tokens[i]);
  28.         }
  29.         free(tokens);
              ^
  30.         row++;
  31.     }


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
        // tokenize the line and process the data
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            fclose(file); // Close the file before returning
            return 1;
        }
        // process the tokens
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
    char** tokens = malloc(100 * sizeof(char*));
    if (tokens == NULL) {
        return NULL;
    }
    char* token;
    int i = 0;
    token = strtok((char*) str, " ");
    while (token != NULL) {
        tokens[i] = malloc(strlen(token) + 1);
        if (tokens[i] == NULL) {
            // Free the memory allocated so far
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}