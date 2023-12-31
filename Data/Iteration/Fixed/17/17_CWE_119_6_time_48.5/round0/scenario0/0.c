List of vulnerabilities detected: 
 Error type: CWE-119 at line: 12. Error message: scanf() without field width limits can crash with huge input data.


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  FILE *fp;
  int line = 1, col = 1;
  char ch;
  // prompt user for filename
  char filename[100];
  printf("Enter filename: ");
  scanf("%s", filename);
  // open file for reading
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  // read and print contents of the file
  printf("\nFile Contents:\n\n");
  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      col++;
    }
  }
  // close the file
  fclose(fp);
  // print line and column count
  printf("\n\nLine count: %d\n", line);
  printf("Column count: %d\n", col);
  return 0;
}