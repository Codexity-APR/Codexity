List of vulnerabilities detected: 
 Error type: CWE-197 at line: 15. Error message: Storing fgetc() return value in char variable and then comparing with EOF.


#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *ptr;
  ptr = fopen("D:\\f4.txt", "r+");
  if (ptr == NULL) {
    printf("File can't be opened");
    exit(0);
  }
  char ch = fgetc(ptr);
  while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(ptr);
  }
  fclose(ptr);
  return 0;
}