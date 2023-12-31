List of vulnerabilities detected: 
Error: Resource Leak   resource acquired to `out` by call to `fopen()` at line 7, column 11 is not released after line 9, column 9.
 Example: 
   7.     out = fopen("output.txt", "w");
   8. 
   9.     if (in == NULL || out == NULL) {
              ^
  10.         printf("Error opening files");
  11.         return 1;

Error: Resource Leak   resource acquired to `in` by call to `fopen()` at line 6, column 10 is not released after line 9, column 23.
 Example: 
   7.     out = fopen("output.txt", "w");
   8. 
   9.     if (in == NULL || out == NULL) {
                            ^
  10.         printf("Error opening files");
  11.         return 1;


#include <stdio.h>
int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL || out == NULL) {
        printf("Error opening files");
        return 1;
    }
    // TODO: Add your code here
    fclose(in);
    fclose(out);
    return 0;
}