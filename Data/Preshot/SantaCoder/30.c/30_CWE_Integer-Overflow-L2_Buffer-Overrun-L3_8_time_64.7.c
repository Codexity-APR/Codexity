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

    // Read each word from file and store in char array
    while (fgets(word, MAX_WORD_LENGTH, file) != NULL) {
        // Remove newline character from word if present
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }
        // Copy word to insouts array
        strncpy(insouts[i], word, MAX_WORD_LENGTH);
        i++;
        // If maximum number of inputs reached, exit loop
        if (i >= MAX_INPUTS) {
            break;
        }
    }
    fclose(file);

    // Print the contents of insouts array
    for (int j = 0; j < i; j++) {
        printf("%s\n", insouts[j]);
    }

    return 0;
}