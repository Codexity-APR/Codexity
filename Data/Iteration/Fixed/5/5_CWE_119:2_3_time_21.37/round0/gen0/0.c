#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    scanf("%s", reference);

    printf("\n Enter query genome file name:  ");
    scanf("%s", query);

    // Rest of your code goes here

    return 0;
}