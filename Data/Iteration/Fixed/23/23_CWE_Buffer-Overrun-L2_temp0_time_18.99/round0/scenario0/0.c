List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [0, 99] Size: 10 by call to `foo`.
 Example: 
  12.     printf("Enter a string: ");
  13.     fgets(input, 100, stdin);
  14.     foo(input);
          ^
  15.     return 0;
  16. }


#include <stdio.h>
#include <string.h>
void foo(char *input) {
    char buf[10];
    strcpy(buf, input);
    printf("Input: %s\n", buf);
}
int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    foo(input);
    return 0;
}