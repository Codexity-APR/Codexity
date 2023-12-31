#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    FILE *file;
    char str[MAX_SIZE];
    int i = 0;
    char c;

    file = fopen("random.txt", "r");

    if (file == NULL) {
        perror("Error while opening the file. ");
        exit(EXIT_FAILURE);
    }

    while ((c = getc(file)) != EOF && i < MAX_SIZE - 1) {
        str[i++] = c;
    }

    str[i] = '\0';

    fclose(file);

    printf("The contents of the file are: %s\n", str);

    return 0;
}