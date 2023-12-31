#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    fgets(reference, sizeof(reference), stdin); // read user input for reference genome file name

    // remove newline character from fgets
    reference[strcspn(reference, "\n")] = '\0';

    printf("\n Enter query genome file name:  ");
    fgets(query, sizeof(query), stdin); // read user input for query genome file name

    // remove newline character from fgets
    query[strcspn(query, "\n")] = '\0';

    // Continue with the rest of your code...
    // ...

    return 0;
}