#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUTS 256
#define MAX_WORD_LENGTH 10

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    char insouts[MAX_INPUTS][MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%9s", word) == 1) {
        if (i >= MAX_INPUTS) {
            printf("Too many inputs in file.\n");
            break;
        }
        strncpy(insouts[i], word, MAX_WORD_LENGTH);
        i++;
    }
    if (!feof(file)) {
        printf("Error while reading file.\n");
        fclose(file);
        return 1;
    }

    for (int j = 0; j < i; j++) {
        printf("%s\n", insouts[j]);
    }

    fclose(file);
    return 0;
}