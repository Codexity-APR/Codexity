#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in, *out;
    char buffer[100];

    in = fopen("flag.txt", "r");
    if (in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    out = fopen("flag_copy.txt", "w");
    if (out == NULL) {
        fclose(in);
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(buffer, 100, in)) {
        fputs(buffer, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}