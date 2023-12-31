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

    while (file) {
        if (file.read(line, 100) == 0) {
            break;
        }

        for (int i = 0; i < 100; i++) {
            if (line[i] == '\n') {
                row++;
                printf("%d\n", row);
                buf = (char*)malloc(100);
            } else {
                strncat(buf, &line[i], 1);
            }
        }

        char **tokens = tokenize(buf);

        if (tokens) {
            for (int i = 0; tokens[i] != NULL; i++) {
                printf("%s ", tokens[i]);
                free(tokens[i]);
            }
        }

        free(tokens);
        free(buf);

        printf("\n");
    }

    file.close();

    return 0;
}

char** tokenize(const char* str) {
    char **tokens = NULL;
    char *token = strtok((char*)str, " ");

    int i = 0;

#ifdef __cplusplus
    tokens = (char**)malloc(sizeof(char*));
#else
    tokens = (char**)malloc(sizeof(char*) * 1);
#endif

    while (token != NULL) {
        tokens[i] = (char*)malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        i++;
#ifdef __cplusplus
        tokens = (char**)realloc(tokens, (i+1)*sizeof(char*));
#else
        tokens = (char**)realloc(tokens, (i+1)*sizeof(char*) * 1);
#endif
        token = strtok(NULL, " ");
    }

    tokens[i] = NULL;

    return tokens;
}