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
        printf("%d\n", row);

        char **tokens = tokenize(line);
        for (int i = 0; tokens[i]; i++) {
            printf("%s\n", tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
    }

    if (buf) {
        free(buf);
    }

    fclose(file);

    return 0;
}

char** tokenize(const char* str) {
    char** result = 0;
    size_t count = 0;
    const char* tmp = str;
    const char* last_comma = 0;
    char delim = ',';

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (str + strlen(str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    result = malloc(sizeof(char*) * (count + 1));

    if (result) {
        size_t idx = 0;
        char* token = strtok((char*)str, &delim);

        while (token) {
            *(result + idx++) = strdup(token);
            token = strtok(0, &delim);
        }
        *(result + idx) = 0;
    }

    return result;
}