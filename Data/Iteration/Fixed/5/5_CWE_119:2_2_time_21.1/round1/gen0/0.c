#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size
    printf("\n Enter reference genome file name:  ");
    scanf("%49s", reference); // limit the input to 49 characters to avoid buffer overflow
    printf("\n Enter query sequence file name:  ");
    scanf("%49s", query); // limit the input to 49 characters to avoid buffer overflow
    // Rest of your code goes here...
    return 0;
}