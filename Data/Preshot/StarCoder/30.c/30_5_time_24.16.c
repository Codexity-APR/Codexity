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

    char insouts[MAX_INPUTS][MAX_WORD_LENGTH+1];
    char word[MAX_WORD_LENGTH+1];
    int i = 0;

    while (fscanf(file, "%10s", word) == 1 && i < MAX_INPUTS) {
        strncpy(insouts[i], word, MAX_WORD_LENGTH);
        insouts[i][MAX_WORD_LENGTH] = '\0';
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%s\n", insouts[j]);
    }

    fclose(file);
    return 0;
}