#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = NULL, *out = NULL;
    char buffer[100];

    in = fopen("flag.txt", "r");
    if (in == NULL) {
        printf("Couldn't open file!\n");
        exit(1);
    }

    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Couldn't create file!\n");
        exit(1);
    }

    if (fgets(buffer, 100, in) != NULL) {
        fputs(buffer, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}