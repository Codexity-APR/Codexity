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

    // read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // remove newline character from the line
        line[strcspn(line, "\n")] = '\0';

        // tokenize the line and process each token
        char** tokens = tokenize(line);
        for (int i = 0; tokens[i]; i++) {
            printf("Token %d: %s\n", i+1, tokens[i]);
            // add your processing code here
        }

        // free memory allocated for tokens
        for (int i = 0; tokens[i]; i++) {
            free(tokens[i]);
        }
        free(tokens);
        
        row++;
    }

    // close the file
    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    const char* delim = " \t\n"; // set of delimiters
    char* buffer = strdup(str); // create a copy of the input string
    int count = 0;
    char** tokens = NULL;

    // get the first token
    char* token = strtok(buffer, delim);

    // iterate over the remaining tokens
    while (token) {
        count++;
        tokens = realloc(tokens, sizeof(char*) * count);
        if (!tokens) {
            // handle allocation failure
            fprintf(stderr, "Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delim);
    }

    // add a NULL terminator to the array of tokens
    count++;
    tokens = realloc(tokens, sizeof(char*) * count);
    if (!tokens) {
        // handle allocation failure
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    tokens[count - 1] = NULL;

    // free the buffer allocated by strdup()
    free(buffer);

    return tokens;
}