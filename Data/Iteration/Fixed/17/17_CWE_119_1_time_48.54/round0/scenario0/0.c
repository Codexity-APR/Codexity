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
  // open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file.\n");
    exit(1);
  }
  // read and print the contents of the file
  printf("Contents of the file:\n");
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
  // print the number of lines and columns in the file
  printf("\nNumber of lines: %d\n", line);
  printf("Number of columns: %d\n", col);
  return 0;
}