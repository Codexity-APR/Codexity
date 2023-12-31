#include <stdio.h>

int main() {
    FILE *in, *out;
    
    // Open input and output files
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    // Check if files were opened successfully
    if (in == NULL || out == NULL) {
        printf("Error opening input or output file.\n");
        return 1;
    }

    // Copy contents of input file to output file
    int c;
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }

    // Close files
    fclose(in);
    fclose(out);

    return 0;
}