#include <stdio.h>

int main() {
    FILE *in, *out;

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening files");
        return 1;
    }

    // TODO: Add your code here

    fclose(in);
    fclose(out);

    return 0;
}