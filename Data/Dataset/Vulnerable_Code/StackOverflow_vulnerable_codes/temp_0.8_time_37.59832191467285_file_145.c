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

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char** tokens = tokenize(line);

        // Process each token
        for (int i = 0; tokens[i] != NULL; i++) {
            // Do something with the token
            printf("%s ", tokens[i]);
        }
        printf("\n");

        // Free memory
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
    // Allocate memory for the tokens array
    char** tokens = malloc(sizeof(char*) * 100);

    // Create a copy of the string to avoid modifying the original
    char* strCopy = strdup(str);

    // Tokenize the string
    char* token = strtok(strCopy, " \t\n");
    int i = 0;
    while (token != NULL) {
        // Allocate memory for each token and copy it
        tokens[i] = strdup(token);
        i++;

        // Get the next token
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;

    // Free the copy of the string
    free(strCopy);

    return tokens;
}