#include <stdio.h>

int main() {
    FILE *in, *out;
    char buffer[100];
    in = fopen("flag.txt", "r");
    if (in == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Unable to open output file.\n");
        return 1;
    }
    while (fgets(buffer, 100, in) != NULL) {
        fputs(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}