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

    if (in == NULL || out == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    int c;
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}