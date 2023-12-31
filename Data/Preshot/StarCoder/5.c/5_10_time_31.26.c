#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    if (scanf("%49s", reference) != 1) { // read in the reference genome file name
        printf("Error reading input.\n");
        return 1;
    }

    printf("\n Enter query genome file name:  ");
    if (scanf("%49s", query) != 1) { // read in the query genome file name
        printf("Error reading input.\n");
        return 1;
    }

    FILE *fp = fopen(reference, "r"); // open the reference genome file
    if (fp == NULL) { // check if the file was opened successfully
        printf("Error opening %s: %s\n", reference, strerror(errno)); // if not, print an error message
        return 1; // exit the program
    }

    FILE *fp2 = fopen(query, "r"); // open the query genome file
    if (fp2 == NULL) { // check if the file was opened successfully
        printf("Error opening %s: %s\n", query, strerror(errno)); // if not, print an error message
        fclose(fp); // close the reference file
        return 1; // exit the program
    }

    // do something with the files

    fclose(fp); // close the reference file
    fclose(fp2); // close the query file
    return 0; // exit the program
}