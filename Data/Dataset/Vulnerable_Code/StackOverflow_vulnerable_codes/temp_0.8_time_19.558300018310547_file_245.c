#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    scanf("%s", reference); // accept user input for reference genome file name

    printf("\n Enter query sequence file name: ");
    scanf("%s", query); // accept user input for query sequence file name

    // Rest of your code goes here...

    return 0;
}