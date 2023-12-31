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

    // read the words from file into insouts array
    while (i < MAX_INPUTS && fscanf(file, "%s", word) == 1) {
        strcpy(insouts[i], word);
        i++;
    }

    fclose(file);

    // print the words in insouts array
    for (int j = 0; j < i; j++) {
        printf("%s\n", insouts[j]);
    }

    return 0;
}