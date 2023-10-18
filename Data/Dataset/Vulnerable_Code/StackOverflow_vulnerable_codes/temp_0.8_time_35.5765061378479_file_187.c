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
        // Tokenize the line
        char** tokens = tokenize(line);
        
        // Process the tokens
        // Your code goes here
        
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
    const char* delimiter = " ";
    char* token;
    char** tokens = malloc(sizeof(char*) * 100);
    int i = 0;

    char* str_copy = strdup(str);
    token = strtok(str_copy, delimiter);

    while (token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delimiter);
    }

    tokens[i] = NULL;
    free(str_copy);

    return tokens;
}