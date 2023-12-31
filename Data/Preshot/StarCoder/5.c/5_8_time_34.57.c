#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    if (scanf("%49s", reference) != 1) { // limit the size of the input and check the return value of scanf
        printf("Error reading input.\n");
        return 1;
    }

    printf("\n Enter query genome file name:  ");
    if (scanf("%49s", query) != 1) { // limit the size of the input and check the return value of scanf
        printf("Error reading input.\n");
        return 1;
    }

    FILE *fp = fopen(reference, "r"); // declare and initialize file pointer
    if (fp == NULL) { // check if the file was opened successfully
        printf("Error opening %s\n", reference);
        printf("Error number: %d\n", errno);
        printf("Error description: %s\n", strerror(errno));
        return 1;
    }

    FILE *fp2 = fopen(query, "r"); // declare and initialize file pointer
    if (fp2 == NULL) { // check if the file was opened successfully
        fclose(fp); // close the first file pointer before exiting the program
        printf("Error opening %s\n", query);
        printf("Error number: %d\n", errno);
        printf("Error description: %s\n", strerror(errno));
        return 1;
    }

    // do some processing here

    fclose(fp); // close the first file pointer
    fclose(fp2); // close the second file pointer
    return 0;
}