#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    scanf("%s", reference); // take input for reference genome file name

    printf("\n Enter query genome file name:  ");
    scanf("%s", query); // take input for query genome file name

    // Your code here

    return 0;
}