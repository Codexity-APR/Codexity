#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    if (scanf("%49s", reference) != 1) // limit the size of input to avoid buffer overflow
    {
        printf("Error reading file name.\n");
        return 1;
    }

    printf("\n Enter query genome file name:  ");
    if (scanf("%49s", query) != 1) // limit the size of input to avoid buffer overflow
    {
        printf("Error reading file name.\n");
        return 1;
    }

    FILE *fp = NULL; // declare file pointer and initialize to NULL
    fp = fopen(reference, "r"); // open the reference genome file

    if (fp == NULL) // check if the file was opened successfully
    {
        printf("Error opening %s\n", reference); // if not, print an error message
        printf("Error number: %d\n", errno); // print the error number
        printf("Error description: %s\n", strerror(errno)); // print the error description
        return 1; // exit the program
    }

    FILE *fp2 = NULL; // declare file pointer and initialize to NULL
    fp2 = fopen(query, "r"); // open the query genome file

    if (fp2 == NULL) // check if the file was opened successfully
    {
        fclose(fp); // close the reference genome file
        printf("Error opening %s\n", query); // if not, print an error message
        printf("Error number: %d\n", errno); // print the error number
        printf("Error description: %s\n", strerror(errno)); // print the error description
        return 1; // exit the program
    }

    // process the files

    fclose(fp); // close the reference genome file
    fclose(fp2); // close the query genome file

    return 0; // exit the program
}