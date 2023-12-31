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
        // Tokenize the line and store the tokens in a char array
        char** tokens = tokenize(line);
        if (tokens == NULL) {
            printf("Failed to tokenize line\n");
            fclose(file); // Close the file before returning
            return 1;
        }
        // Process the tokens as needed
        // Increment row count
        row++;
        // Free the memory allocated for tokens
        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
    // Close the file
    fclose(file);
    return 0;
}

char** tokenize(const char* str) {
    char** tokens = NULL;
    char* token = strtok((char*)str, " \t\n");
    int count = 0;
    // Tokenize the string and store the tokens in a char array
    while (token) {
        char** temp = realloc(tokens, sizeof(char*) * (count+1));
        if (temp == NULL) {
            // Handle realloc failure
            for (int i = 0; i < count; i++) {
                free(tokens[i]);
            }
            free(tokens);
            return NULL;
        }
        tokens = temp;
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, " \t\n");
    }
    return tokens;
}