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
        
        // Code to process tokens
        
        row++;
    }
    
    fclose(file);
    
    return 0;
}

char** tokenize(const char* str) {
    const char* delim = " ";
    int size = 2; // Assuming the maximum number of tokens is 2
    char** tokens = (char**)malloc(size * sizeof(char*));
    
    char* token = strtok((char*)str, delim);
    int i = 0;
    
    while (token != NULL) {
        tokens[i] = (char*)malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        
        token = strtok(NULL, delim);
        i++;
    }
    
    return tokens;
}