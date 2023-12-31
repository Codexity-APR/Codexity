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
        // ...

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

char** tokenize(const char* str) {
    const char* delimiters = " \t\n";
    char* token;
    int num_tokens = 0;

    // Count the number of tokens
    char* str_copy = strdup(str);
    token = strtok(str_copy, delimiters);
    while (token != NULL) {
        num_tokens++;
        token = strtok(NULL, delimiters);
    }
    free(str_copy);

    // Allocate memory for the tokens
    char** tokens = (char**)malloc((num_tokens + 1) * sizeof(char*));

    // Tokenize the string again and store the tokens
    str_copy = strdup(str);
    token = strtok(str_copy, delimiters);
    int i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delimiters);
    }
    tokens[i] = NULL;
    free(str_copy);

    return tokens;
}