#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

int main(void)
{
    char reference[MAX_FILENAME_LENGTH], query[MAX_FILENAME_LENGTH]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name: ");
    if (scanf("%49s", reference) != 1) // read in the reference genome file name
    {
        printf("Error reading input.\n");
        return 1; // exit the program
    }

    printf("\n Enter query genome file name: ");
    if (scanf("%49s", query) != 1) // read in the query genome file name
    {
        printf("Error reading input.\n");
        return 1; // exit the program
    }

    FILE *fp = fopen(reference, "r"); // open the reference genome file
    if (fp == NULL) // check if the file was opened successfully
    {
        printf("Error opening %s: %s\n", reference, strerror(errno)); // if not, print an error message
        return 1; // exit the program
    }

    FILE *fp2 = fopen(query, "r"); // open the query genome file
    if (fp2 == NULL) // check if the file was opened successfully
    {
        printf("Error opening %s: %s\n", query, strerror(errno)); // if not, print an error message
        fclose(fp); // close the previously opened file
        return 1; // exit the program
    }

    // Your code goes here

    fclose(fp); // close the files when you're done with them
    fclose(fp2);

    return 0; // exit the program
}