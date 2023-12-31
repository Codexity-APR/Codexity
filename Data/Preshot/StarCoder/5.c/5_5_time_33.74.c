#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50

int main(void)
{
    char reference[MAX_FILENAME_SIZE], query[MAX_FILENAME_SIZE];
    FILE *fp = NULL, *fp2 = NULL;

    printf("\nEnter reference genome file name: ");
    if (scanf("%49s", reference) != 1) {
        fprintf(stderr, "Error: Failed to read input.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter query genome file name: ");
    if (scanf("%49s", query) != 1) {
        fprintf(stderr, "Error: Failed to read input.\n");
        return EXIT_FAILURE;
    }

    fp = fopen(reference, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file %s - %s.\n", reference, strerror(errno));
        return EXIT_FAILURE;
    }

    fp2 = fopen(query, "r");
    if (fp2 == NULL) {
        fprintf(stderr, "Error: Failed to open file %s - %s.\n", query, strerror(errno));
        fclose(fp);
        return EXIT_FAILURE;
    }

    // TODO: rest of the code

    fclose(fp);
    fclose(fp2);
    return EXIT_SUCCESS;
}