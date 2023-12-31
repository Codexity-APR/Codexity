#include <stdio.h>

int main() {
    FILE *in, *out;
    // Open input file for reading
    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    // Open output file for writing
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error opening output file.\n");
        fclose(in); // Close the input file before returning
        return 1;
    }
    // Code to read from input file and write to output file goes here
    // Close the files
    fclose(in);
    fclose(out);
    return 0;
}