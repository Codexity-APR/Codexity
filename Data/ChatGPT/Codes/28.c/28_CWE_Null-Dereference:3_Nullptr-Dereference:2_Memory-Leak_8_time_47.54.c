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
        // Tokenize each line
        char** tokens = tokenize(line);

        // Process the tokens
        for (int i = 0; tokens[i] != NULL; i++) {
            // Do something with the token
            printf("%s ", tokens[i]);
        }
        printf("\n");

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
    const char delimiter[2] = " ";
    char* token;

    // Allocate memory for tokens array
    char** tokens = malloc(sizeof(char*) * 100);
    int tokenCount = 0;

    // Tokenize the string
    char* strCopy = strdup(str);
    token = strtok(strCopy, delimiter);
    while (token != NULL) {
        // Allocate memory for each token
        tokens[tokenCount] = malloc(strlen(token) + 1);
        strcpy(tokens[tokenCount], token);
        tokenCount++;

        token = strtok(NULL, delimiter);
    }
    tokens[tokenCount] = NULL;

    free(strCopy);

    return tokens;
}