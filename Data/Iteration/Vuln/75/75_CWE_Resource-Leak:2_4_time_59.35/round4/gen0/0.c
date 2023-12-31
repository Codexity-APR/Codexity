#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL) {
        printf("Failed to open input file.");
        return 1;
    }
    if (out == NULL) {
        printf("Failed to open output file.");
        fclose(in);
        return 1;
    }
    // Rest of your code goes here

    fclose(in);
    fclose(out);
    return 0;
}