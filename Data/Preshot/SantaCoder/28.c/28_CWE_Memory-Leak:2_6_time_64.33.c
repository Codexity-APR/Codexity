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
        for (int i = 0; i < 100; i++) {
            if (line[i] == '\n') {
                row++;
                printf("%d\n", row);
                buf = (char*)malloc(100);
            }
        }
    }

    if (buf) {
        free(buf);
    }

    fclose(file);

    return 0;
}