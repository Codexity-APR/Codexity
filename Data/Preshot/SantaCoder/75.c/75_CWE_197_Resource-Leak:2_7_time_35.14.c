#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char c = fgetc(in);
    while (c != EOF) {
        fputc(c, out);
        c = fgetc(in);
    }

    fclose(in);
    fclose(out);

    return 0;
}