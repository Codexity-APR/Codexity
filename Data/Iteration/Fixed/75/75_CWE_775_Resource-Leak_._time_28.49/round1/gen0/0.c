#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Unable to open input file.\n");
        return 1;
    }
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Unable to open output file.\n");
        fclose(in); // Close the input file before returning
        return 1;
    }
    // Rest of the code
    fclose(in);
    fclose(out);
    return 0;
}