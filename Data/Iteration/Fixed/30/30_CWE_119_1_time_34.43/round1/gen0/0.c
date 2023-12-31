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
    while (fscanf(file, "%9s", word) == 1) { // Limiting field width to 9 characters
        strcpy(insouts[i], word);
        i++;
    }
    fclose(file);
    // Rest of your code...
    return 0;
}