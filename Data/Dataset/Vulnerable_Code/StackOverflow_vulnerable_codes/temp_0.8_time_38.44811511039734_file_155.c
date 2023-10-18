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
        // Tokenize the line and store the tokens in a variable
        char** tokens = tokenize(line);

        // Do something with the tokens

        // Free the memory allocated for the tokens
        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);

        // Increment the row counter
        row++;
    }

    // Close the file
    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    // Determine the number of tokens in the string
    int num_tokens = 0;
    char* temp_str = strdup(str);
    char* token = strtok(temp_str, " ");
    while (token != NULL) {
        num_tokens++;
        token = strtok(NULL, " ");
    }
    free(temp_str);

    // Allocate memory for the array of tokens
    char** tokens = (char**)malloc((num_tokens + 1) * sizeof(char*));

    // Tokenize the string and store the tokens in the array
    temp_str = strdup(str);
    token = strtok(temp_str, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    free(temp_str);

    return tokens;
}