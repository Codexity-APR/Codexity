#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        if (in != NULL) {
            fclose(in);
        }
        if (out != NULL) {
            fclose(out);
        }
        return 1;
    }
    // Rest of the code goes here
    fclose(in);
    fclose(out);
    return 0;
}