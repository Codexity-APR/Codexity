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

    // Read each line of the file
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char** tokens = tokenize(line);
        
        // Process the tokens
        
        // Free the memory allocated for tokens
        free(tokens);
        
        row++;
    }

    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    const char* delimiter = " ";
    char* token;
    int numTokens = 0;
    
    // Count the number of tokens
    char* copy = strdup(str);
    token = strtok(copy, delimiter);
    while (token) {
        numTokens++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    
    // Allocate memory for tokens
    char** tokens = (char**)malloc((numTokens + 1) * sizeof(char*));
    
    // Tokenize the string again and store each token
    copy = strdup(str);
    token = strtok(copy, delimiter);
    int i = 0;
    while (token) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    
    // Set the last token as NULL
    tokens[numTokens] = NULL;
    
    return tokens;
}