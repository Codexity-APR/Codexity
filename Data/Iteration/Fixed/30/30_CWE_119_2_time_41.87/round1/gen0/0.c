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
        strcpy(insouts[i], word);
        i++;
        if (i >= MAX_INPUTS) {
            printf("Maximum number of inputs reached.\n");
            break;
        }
    }

    fclose(file);

    for (int j = 0; j < i; j++) {
        printf("Input/Output %d: %s\n", j+1, insouts[j]);
    }

    return 0;
}