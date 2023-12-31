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
        // Tokenize the line into an array of strings
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            return 1;
        }
        // Process the tokens as needed
        // Free memory for the tokens
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
    char** tokens = malloc(sizeof(char*));
    if (tokens == NULL) {
        return NULL;
    }
    char* token = strtok(str, " \t\n");
    int i = 0;
    while (token != NULL) {
        tokens[i] = malloc(strlen(token) + 1);
        if (tokens[i] == NULL) {
            // Handle allocation failure
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        strcpy(tokens[i], token);
        i++;
        tokens = realloc(tokens, (i + 1) * sizeof(char*));
        if (tokens == NULL) {
            // Handle reallocation failure
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return tokens;
}