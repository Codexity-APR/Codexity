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
        // Tokenize the line
        char** tokens = tokenize(line);
        
        // Process the tokens
        
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
    
    // Count the number of tokens
    int count = 0;
    char* copy = strdup(str);
    token = strtok(copy, delimiter);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    
    // Allocate memory for tokens
    char** tokens = malloc((count + 1) * sizeof(char*));
    copy = strdup(str);
    token = strtok(copy, delimiter);
    
    // Store the tokens
    int i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        token = strtok(NULL, delimiter);
        i++;
    }
    tokens[i] = NULL;
    free(copy);
    
    return tokens;
}