#include <stdio.h>

int main() {
    FILE *in, *out;
    char buffer[100];
    in = fopen("flag.txt", "r");
    if (in == NULL) {
        perror("Error opening input file");
        return 1;
    }
    out = fopen("output.txt", "w");
    if (out == NULL) {
        perror("Error opening output file");
        return 1;
    }
    if (fgets(buffer, 100, in) != NULL) {
        fputs(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}