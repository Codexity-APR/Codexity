#include <stdio.h>
#include <string.h>

int main(void)
{
    char reference[50], query[50]; // declare character arrays with sufficient size

    printf("\nEnter reference genome file name: ");
    scanf("%49s", reference); // read in the reference genome file name with field width limit
    
    printf("\nEnter query genome file name: ");
    scanf("%49s", query); // read in the query genome file name with field width limit
    
    FILE *fp = fopen(reference, "r"); // open the reference genome file
    if (fp == NULL) // check if the file was opened successfully
    {
        printf("Error opening %s\n", reference); // if not, print an error message
        perror("Error description"); // print the error description
        return 1; // exit the program
    }

    FILE *fp2 = fopen(query, "r"); // open the query genome file
    if (fp2 == NULL) // check if the file was opened successfully
    {
        printf("Error opening %s\n", query); // if not, print an error message
        perror("Error description"); // print the error description
        fclose(fp); // close the reference genome file
        return 1; // exit the program
    }
    
    // Do the necessary processing
    
    fclose(fp); // close the reference genome file
    fclose(fp2); // close the query genome file
    
    return 0; // exit the program with success
}