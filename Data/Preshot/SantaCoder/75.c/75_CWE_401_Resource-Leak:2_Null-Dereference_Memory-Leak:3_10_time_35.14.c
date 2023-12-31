#include <stdio.h>

int main() {
    FILE *in, *out;
    char *buf = malloc(1024);

    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    while (fgets(buf, 1024, in)) {
        fputs(buf, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}