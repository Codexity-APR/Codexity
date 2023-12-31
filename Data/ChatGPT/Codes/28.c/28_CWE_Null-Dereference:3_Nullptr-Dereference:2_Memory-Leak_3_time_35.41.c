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
        // tokenize the line and process the data
        
        char** tokens = tokenize(line);
        
        // process the tokens
        
        row++;
    }

    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char** tokens = malloc(100 * sizeof(char*));
    char* token;
    int i = 0;
    
    token = strtok((char*) str, " ");
    
    while (token != NULL) {
        tokens[i] = malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    
    tokens[i] = NULL;
    
    return tokens;
}