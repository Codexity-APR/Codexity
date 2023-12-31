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
        printf("Unable to open file.\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        fputs(buffer, out);
    }

    fclose(in);
    fclose(out);

    printf("File copied successfully.\n");

    return 0;
}