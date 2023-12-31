#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL || out == NULL) {
        printf("Failed to open file.");
        fclose(in);
        fclose(out);
        return 1;
    }
    // Rest of your code goes here
    fclose(in);
    fclose(out);
    return 0;
}