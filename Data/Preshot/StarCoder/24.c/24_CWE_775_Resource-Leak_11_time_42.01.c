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

    // rest of the code
    return 0;
}

char** tokenize(const char* str) {
    const char* delim = " \t\n";
    char* copy = strdup(str);
    if (!copy) {
        return NULL;
    }

    char** tokens = NULL;
    char* token = strtok(copy, delim);
    size_t count = 0;
    while (token) {
        ++count;
        void* temp = realloc(tokens, count * sizeof(char*));
        if (!temp) {
            free(copy);
            free(tokens);
            return NULL;
        }
        tokens = temp;
        tokens[count - 1] = token;
        token = strtok(NULL, delim);
    }

    if (count == 0 && tokens) {
        free(tokens);
        tokens = NULL;
    }

    free(copy);
    return tokens;
}