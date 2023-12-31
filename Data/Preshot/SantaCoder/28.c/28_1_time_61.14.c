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

#ifdef __cplusplus
    char *buf = (char*)malloc(100);
#else
    char *buf = (char*)malloc(100 * sizeof(char));
#endif

    while (fgets(line, 100, file)) {
        row++;
        printf("Row %d: %s", row, line);
        char** tokens = tokenize(line);
        // do something with the tokens
        free(tokens);
    }

    if (buf) {
        free(buf);
    }

    fclose(file);

    return 0;
}