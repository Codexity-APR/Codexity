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
    // Read each line from file
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            return 1;
        }
        // Process the tokens
        // Free the memory allocated for tokens
        for (int i = 0; tokens[i]; i++) {
            free(tokens[i]);
        }
        free(tokens);
        row++;
    }
    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    // Count the number of tokens
    int count = 0;
    char* copy = strdup(str);
    if (copy == NULL) {
        printf("Failed to duplicate string\n");
        return NULL;
    }
    char* token = strtok(copy, " \t\n");
    while (token) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    free(copy);
    // Allocate memory for tokens
    char** tokens = (char**)malloc((count + 1) * sizeof(char*));
    if (tokens == NULL) {
        printf("Failed to allocate memory for tokens\n");
        return NULL;
    }
    // Tokenize the string and store tokens
    copy = strdup(str);
    if (copy == NULL) {
        printf("Failed to duplicate string\n");
        free(tokens);
        return NULL;
    }
    token = strtok(copy, " \t\n");
    int i = 0;
    while (token) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            printf("Failed to duplicate token\n");
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            free(copy);
            return NULL;
        }
        i++;
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    free(copy);
    return tokens;
}