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

    // Read words from file and store them in the insouts array
    while (fgets(word, MAX_WORD_LENGTH, file) != NULL) {
        // Remove newline character if present
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }
        strncpy(insouts[i], word, MAX_WORD_LENGTH);
        i++;
    }

    fclose(file);

    // Print the words stored in the insouts array
    for (int j = 0; j < i; j++) {
        printf("Word %d: %s\n", j+1, insouts[j]);
    }

    return 0;
}