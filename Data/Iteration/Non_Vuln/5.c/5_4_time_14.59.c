#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    fgets(reference, sizeof(reference), stdin);
    reference[strcspn(reference, "\n")] = '\0'; // remove the trailing newline character

    printf("\n Enter query sequence file name:  ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0'; // remove the trailing newline character

    // Rest of the code...

    return 0;
}