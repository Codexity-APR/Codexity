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

    // Read file line by line
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char** tokens = tokenize(line);

        // Process each token
        for (int i = 0; tokens[i] != NULL; i++) {
            // Do something with the token, e.g. print it
            printf("%s ", tokens[i]);

            // Free memory allocated for the token
            free(tokens[i]);
        }

        // Free memory allocated for the tokens array
        free(tokens);

        // Increment the row count
        row++;
    }

    // Close the file
    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    const char* delimiter = " ";
    char* token;

    // Allocate memory for tokens array
    char** tokens = malloc(sizeof(char*));

    // Copy the input string
    char* input = malloc(strlen(str) + 1);
    strcpy(input, str);

    // Tokenize the string
    token = strtok(input, delimiter);
    int i = 0;
    while (token != NULL) {
        // Allocate memory for the token
        tokens[i] = malloc(strlen(token) + 1);

        // Copy the token
        strcpy(tokens[i], token);

        // Get the next token
        token = strtok(NULL, delimiter);

        // Increment the token count
        i++;

        // Resize the tokens array
        tokens = realloc(tokens, (i + 1) * sizeof(char*));
    }

    // Add a NULL terminator at the end of tokens array
    tokens[i] = NULL;

    // Free memory allocated for input string
    free(input);

    return tokens;
}