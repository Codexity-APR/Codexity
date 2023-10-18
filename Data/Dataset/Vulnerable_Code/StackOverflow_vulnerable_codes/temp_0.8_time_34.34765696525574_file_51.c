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
    
    // Read lines from the file and tokenize them
    while (fgets(line, sizeof(line), file)) {
        char** tokens = tokenize(line);
        
        // Process the tokens here
        
        row++;
    }

    fclose(file);
    
    return 0;
}

char** tokenize(const char* str) {
    char** tokens = NULL;
    char* token = strtok((char*)str, " \t\n");
    int count = 0;

    while (token) {
        tokens = realloc(tokens, sizeof(char*) * (count + 1));
        tokens[count] = strdup(token);
        count++;

        token = strtok(NULL, " \t\n");
    }

    tokens = realloc(tokens, sizeof(char*) * (count + 1));
    tokens[count] = NULL;

    return tokens;
}