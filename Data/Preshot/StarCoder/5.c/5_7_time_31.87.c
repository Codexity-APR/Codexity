#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    if (scanf("%49s", reference) != 1) { // read in the reference genome file name
        fprintf(stderr, "Error: Reading input failed.\n");
        return 1; // exit the program with error status
    }

    printf("\n Enter query genome file name:  ");
    if (scanf("%49s", query) != 1) { // read in the query genome file name
        fprintf(stderr, "Error: Reading input failed.\n");
        return 1; // exit the program with error status
    }

    FILE *fp = fopen(reference, "r"); // open the reference genome file
    if (!fp) { // check if the file was opened successfully
        fprintf(stderr, "Error: Failed to open file %s (%s).\n", reference, strerror(errno));
        return 1; // exit the program with error status
    }

    FILE *fp2 = fopen(query, "r"); // open the query genome file
    if (!fp2) { // check if the file was opened successfully
        fprintf(stderr, "Error: Failed to open file %s (%s).\n", query, strerror(errno));
        fclose(fp); // close the previously opened file
        return 1; // exit the program with error status
    }

    // use the files

    fclose(fp); // close the reference genome file
    fclose(fp2); // close the query genome file

    return 0; // exit the program successfully
}