#include <stdio.h>

int main() {
    FILE *in, *out;

    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Rest of your code goes here

    fclose(in);
    fclose(out);
    return 0;
}