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

    while (fgets(word, MAX_WORD_LENGTH, file) != NULL && i < MAX_INPUTS) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character from word
        strcpy(insouts[i], word);
        i++;
    }

    fclose(file);

    // Printing the inputs and outputs
    for (int j = 0; j < i; j++) {
        printf("Input/Output: %s\n", insouts[j]);
    }

    return 0;
}