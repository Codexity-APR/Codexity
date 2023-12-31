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

    // Remove trailing newline characters from input
    reference[strcspn(reference, "\n")] = '\0';
    query[strcspn(query, "\n")] = '\0';

    // Rest of your code goes here...

    return 0;
}