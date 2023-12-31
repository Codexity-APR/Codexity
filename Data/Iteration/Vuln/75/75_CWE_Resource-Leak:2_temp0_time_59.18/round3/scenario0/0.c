List of vulnerabilities detected: 
Error: Resource Leak   resource acquired to `out` by call to `fopen()` at line 6, column 11 is not released after line 7, column 9.
 Example: 
  5.     in = fopen("input.txt", "r");
  6.     out = fopen("output.txt", "w");
  7.     if (in == NULL || out == NULL) {
             ^
  8.         printf("Error opening files.\n");
  9.         return 1;

Error: Resource Leak   resource acquired to `in` by call to `fopen()` at line 5, column 10 is not released after line 7, column 23.
 Example: 
  5.     in = fopen("input.txt", "r");
  6.     out = fopen("output.txt", "w");
  7.     if (in == NULL || out == NULL) {
                           ^
  8.         printf("Error opening files.\n");
  9.         return 1;


#include <stdio.h>
int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL || out == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    // Rest of your code goes here
    fclose(in);
    fclose(out);
    return 0;
}