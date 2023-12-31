#include <stdio.h>

int main() {
    FILE *in, *out;
    char buffer[100];
    in = fopen("flag.txt", "r");
    if (in == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1; // Exit the program with an error code
    }
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(in);
        return 1; // Exit the program with an error code
    }
    fgets(buffer, 100, in);
    fputs(buffer, out);
    fclose(in);
    fclose(out);
    printf("File copied successfully.\n");
    return 0;
}