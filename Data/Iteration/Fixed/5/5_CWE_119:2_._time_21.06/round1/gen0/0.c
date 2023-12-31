#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size
    printf("\n Enter reference genome file name:  ");
    scanf("%49s", reference);  // limit the input size to 49 characters for reference genome file name
    printf("\n Enter query genome file name:  ");
    scanf("%49s", query);  // limit the input size to 49 characters for query genome file name
    // Rest of the code goes here
    return 0;
}