#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\n Enter reference genome file name:  ");
    scanf("%s", reference); // read user input for reference genome file name

        printf("\n Enter query genome file name:  ");
        scanf("%s", query); // read user input for query genome file name

        FILE *ref_file = fopen(reference, "r"); // open reference genome file in read mode
        FILE *query_file = fopen(query, "r"); // open query genome file in read mode

        if (ref_file == NULL || query_file == NULL) // check if either file failed to open
        {
            printf("\n Error: %s\n", strerror(errno)); // print error message
            return 1; // return error code
        }

        // rest of the code goes here
    }
