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

  // open file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open file %s\n", filename);
    exit(1);
  }

  // read file character by character
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      col++;
    }
  }

  // close file
  fclose(fp);

  // print number of lines and columns
  printf("Number of lines: %d\n", line);
  printf("Number of columns: %d\n", col);
  
  return 0;
}