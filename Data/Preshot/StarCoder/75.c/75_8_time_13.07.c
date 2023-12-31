#include <stdio.h>

int main() {
    FILE *in = NULL, *out = NULL;
    char buffer[100];
    in = fopen("flag.txt", "r");
    if (in != NULL) {
        out = fopen("output.txt", "w");
        if (out != NULL) {
            fgets(buffer, 100, in);
            fputs(buffer, out);
            fclose(out);
        }
        fclose(in);
    }
    return 0;
}