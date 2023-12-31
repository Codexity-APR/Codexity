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

    char buffer[1024];
    size_t bytesRead = 0;

    if (in && out) {
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), in)) > 0) {
            fwrite(buffer, 1, bytesRead, out);
        }

        fclose(in);
        fclose(out);

        printf("File copied successfully.\n");
    }
    else {
        printf("Error: Unable to open file.\n");
    }

    return 0;
}