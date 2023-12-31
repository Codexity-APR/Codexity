#include <stdio.h>

int main() {
    FILE *in, *out;

#ifdef __cplusplus
    // Use stdio.h instead of stdio.h from the standard library.
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
#else
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
#endif

    char buf[1024];
    size_t nread;

    while ((nread = fread(buf, 1, sizeof buf, in)) > 0) {
        fwrite(buf, 1, nread, out);
    }

    if (ferror(in)) {
        printf("Error reading from input file\n");
    }

    if (ferror(out)) {
        printf("Error writing to output file\n");
    }

    fclose(in);
    fclose(out);

    return 0;
}