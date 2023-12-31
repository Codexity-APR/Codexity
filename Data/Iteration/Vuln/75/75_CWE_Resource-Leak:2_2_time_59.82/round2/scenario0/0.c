List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `fopen()` at line 6, column 11 is not released after line 8, column 9.
 Example: 
   6.     out = fopen("output.txt", "w");
   7.     if (in == NULL) {
   8.         printf("Error opening input file");
              ^
   9.         return 1;
  10.     }

 Error type: CWE-775 at line: 9. Error message: Resource leak: out


#include <stdio.h>
int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    if (in == NULL) {
        printf("Error opening input file");
        return 1;
    }
    if (out == NULL) {
        printf("Error opening output file");
        fclose(in);
        return 1;
    }
    // TODO: Add your code here
    fclose(in);
    fclose(out);
    return 0;
}