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

	while (i < MAX_INPUTS) {
        char *buf = file.read(MAX_WORD_LENGTH);
        if (buf == NULL) {
            printf("File could not be read.\n");
            return 1;
        }
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            word[j] = buf[j];
        }
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            insouts[i][j] = word[j];
        }
        i++;
    }

    file.close();

    for (int i = 0; i < MAX_INPUTS; i++) {
        printf("%s\n", insouts[i]);
    }

    return 0;
}