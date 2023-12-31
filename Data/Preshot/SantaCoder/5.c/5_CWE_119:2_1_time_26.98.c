#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    scanf("%s", reference); // get input from user and store it in reference array

    printf("\n Enter query sequence file name:  ");
    scanf("%s", query); // get input from user and store it in query array

    // further code goes here

    return 0;
}