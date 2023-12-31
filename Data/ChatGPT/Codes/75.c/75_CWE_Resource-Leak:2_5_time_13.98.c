#include <stdio.h>

int main() {
    FILE *in, *out;
    
    in = fopen("input.txt", "r"); // Open input file in read mode
    out = fopen("output.txt", "w"); // Open output file in write mode
    
    if (in == NULL || out == NULL) {
        printf("Error opening files.\n");
        return 1; // return an error code
    }
    
    // Rest of your code goes here
    
    fclose(in); // Close input file
    fclose(out); // Close output file
    
    return 0; // return 0 to indicate successful execution
}