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

    while (fgets(line, 100, file)) {
        char** tokens = tokenize(line);
        
        // Use the tokens here
        
        free(tokens);
        row++;
    }

    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    char* dup = strdup(str);
    char* token = strtok(dup, " ");
    int count = 0;
    char** tokens = NULL;

    while (token != NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char*) * count);

        if (tokens == NULL) {
            fprintf(stderr, "Failed to allocate memory for tokens\n");
            exit(1);
        }

        tokens[count - 1] = strdup(token);
        token = strtok(NULL, " ");
    }

    free(dup);
    return tokens;
}