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
        
        // Free the memory allocated for tokens
        for (int i = 0; tokens[i]; i++) {
            free(tokens[i]);
        }
        free(tokens);
        
        row++;
    }
    
    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char** tokens = malloc(sizeof(char*) * 10);
    int token_count = 0;
    char* token = strtok(str, " \t\n");
    
    while (token) {
        tokens[token_count] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[token_count], token);
        token_count++;
        token = strtok(NULL, " \t\n");
    }
    
    tokens[token_count] = NULL;
    
    return tokens;
}