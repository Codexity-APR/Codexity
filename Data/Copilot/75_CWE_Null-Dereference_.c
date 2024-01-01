#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
        out = fopen("output.txt", "w");

        int num;
        fscanf(in, "%d", &num);
        fprintf(out, "The number is %d\n", num);

        fclose(in);
        fclose(out);

        return 0;
    }
