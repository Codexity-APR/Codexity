#include <stdio.h>

int main() {
    FILE *in, *out;
    
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    // Check if file opening was successful
    if (in == NULL || out == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Your code goes here

    // Close the files
    fclose(in);
    fclose(out);

    return 0;
}