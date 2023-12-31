#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL) {
        printf("Error opening input file");
        return 1;
    }
    if (out == NULL) {
        printf("Error opening output file");
        fclose(in);
        return 1;
    }
    // TODO: Add your code here
    fclose(in);
    fclose(out);
    return 0;
}