#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    fgets(reference, sizeof(reference), stdin); // read user input for reference genome file name

    printf("\n Enter query genome file name:  ");
    fgets(query, sizeof(query), stdin); // read user input for query genome file name

    reference[strcspn(reference, "\n")] = '\0'; // remove newline character from reference string
    query[strcspn(query, "\n")] = '\0'; // remove newline character from query string

    // Rest of your code goes here

    return 0;
}