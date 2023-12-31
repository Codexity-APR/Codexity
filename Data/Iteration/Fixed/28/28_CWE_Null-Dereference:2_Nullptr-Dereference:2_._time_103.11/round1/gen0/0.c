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
    // Read lines from the file
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            return 1;
        }
        // Process the tokens
        int col = 0;
        while (tokens[col] != NULL) {
            // Do something with each token
            printf("Token: %s\n", tokens[col]);
            col++;
        }
        // Free the tokens
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
    char** tokens = malloc(sizeof(char*) * 10); // Assuming a maximum of 10 tokens per line
    if (tokens == NULL) {
        return NULL;
    }
    int i = 0;
    // Tokenize the string
    token = strtok((char*)str, delimiter);
    while (token != NULL) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            // Handle memory allocation failure
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        i++;
        token = strtok(NULL, delimiter);
    }
    tokens[i] = NULL;  // Mark the end of tokens with NULL
    return tokens;
}