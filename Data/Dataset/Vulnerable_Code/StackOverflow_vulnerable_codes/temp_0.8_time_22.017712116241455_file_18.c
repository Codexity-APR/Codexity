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
        char** tokens = tokenize(line);
        
        // Rest of the code
        
        row++;
    }

    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    char** tokens = malloc(sizeof(char*) * 100);
    char* token = strtok(str, " \t\n");
    int i = 0;

    while (token != NULL) {
        tokens[i] = malloc(strlen(token) + 1);
        strcpy(tokens[i], token);

        token = strtok(NULL, " \t\n");
        i++;
    }

    tokens[i] = NULL;
    return tokens;
}