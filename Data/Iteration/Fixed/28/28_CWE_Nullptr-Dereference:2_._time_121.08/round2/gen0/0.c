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
        if (tokens == NULL) {
            // Handle allocation failure
            printf("Failed to tokenize line\n");
            fclose(file);
            return 1;
        }
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
    int numTokens = 0;
    // Count the number of tokens
    char* copy = strdup(str);
    if (copy == NULL) {
        // Handle allocation failure
        return NULL;
    }
    token = strtok(copy, delimiter);
    while (token) {
        numTokens++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    // Allocate memory for tokens
    char** tokens = (char**)malloc((numTokens + 1) * sizeof(char*));
    if (tokens == NULL) {
        // Handle allocation failure
        return NULL;
    }
    // Tokenize the string again and store each token
    copy = strdup(str);
    if (copy == NULL) {
        // Handle allocation failure
        free(tokens);
        return NULL;
    }
    token = strtok(copy, delimiter);
    int i = 0;
    while (token) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            // Handle allocation failure
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            free(copy);
            return NULL;
        }
        i++;
        token = strtok(NULL, delimiter);
    }
    free(copy);
    // Set the last token as NULL
    tokens[numTokens] = NULL;
    return tokens;
}