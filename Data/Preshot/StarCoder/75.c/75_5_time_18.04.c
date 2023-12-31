#include <stdio.h>

int main() {
    FILE *in, *out;
    char buffer[100];
    in = fopen("flag.txt", "r");
    if (in == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Could not create output file.\n");
        fclose(in);
        return 1;
    }
    while (fgets(buffer, 100, in) != NULL) {
        fputs(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}