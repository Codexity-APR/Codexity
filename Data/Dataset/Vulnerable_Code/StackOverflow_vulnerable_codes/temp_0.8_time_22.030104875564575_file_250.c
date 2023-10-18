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

    // Reading words from file and storing in insouts array
    while (fscanf(file, "%s", word) != EOF) {
        strcpy(insouts[i], word);
        i++;
    }

    // Printing the words from insouts array
    for (int j = 0; j < i; j++) {
        printf("Word %d: %s\n", j+1, insouts[j]);
    }

    fclose(file);
    return 0;
}