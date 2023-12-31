#include <stdio.h>

int main() {
    FILE *in, *out;

#ifdef __cplusplus
    // Use stdio.h instead of iostream from the standard library.
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
#else
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
#endif

    if (in == NULL || out == NULL) {
        printf("Error opening file!");
        return 1;
    }

    char buf[1024];
    size_t numBytes = fread(buf, sizeof(char), sizeof(buf), in);
    while (numBytes > 0) {
        fwrite(buf, sizeof(char), numBytes, out);
        numBytes = fread(buf, sizeof(char), sizeof(buf), in);
    }

    fclose(in);
    fclose(out);

    return 0;
}