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
        word[strcspn(word, "\n")] = '\0'; // remove trailing newline
        strcpy(insouts[i], word);
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%s\n", insouts[j]);
    }

    fclose(file);
    return 0;
}