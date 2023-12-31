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

    while (fgets(word, sizeof(word), file) != NULL) {
        word[strcspn(word, "\n")] = '\0'; // Remove trailing newline character

        strncpy(insouts[i], word, sizeof(insouts[i]) - 1);
        insouts[i][sizeof(insouts[i]) - 1] = '\0'; // Ensure null-termination

        i++;
        
        if (i >= MAX_INPUTS) {
            printf("Maximum number of inputs reached.\n");
            break;
        }
    }

    fclose(file);

    // Printing the inputs and outputs
    for (int j = 0; j < i; j++) {
        printf("Input/Output %d: %s\n", j + 1, insouts[j]);
    }

    return 0;
}