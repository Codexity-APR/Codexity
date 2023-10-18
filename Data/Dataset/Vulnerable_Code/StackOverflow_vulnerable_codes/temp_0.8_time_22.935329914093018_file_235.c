#include <stdio.h>

int main() {
    FILE *in, *out;
    
    // Open the input file in read mode
    in = fopen("input.txt", "r");
    
    // Open the output file in write mode
    out = fopen("output.txt", "w");
    
    // Check if both files were opened successfully
    if (in != NULL && out != NULL) {
        // File operations here
        
        // Close the input and output files
        fclose(in);
        fclose(out);
    } else {
        // Error handling if opening files failed
        printf("Failed to open files.\n");
    }
    
    return 0;
}