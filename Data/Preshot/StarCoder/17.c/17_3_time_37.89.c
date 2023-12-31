#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int line = 1, col = 1;
  char ch;

  // prompt user for filename
  char filename[100];
  printf("Enter filename: ");

  // read filename with secure input handling
  if (fgets(filename, sizeof(filename), stdin) == NULL) {
    printf("Error reading filename\n");
    exit(1);
  } else {
    // remove newline character
    filename[strcspn(filename, "\n")] = '\0';
  }

  // open file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  // read file
  while ((ch = fgetc(fp))!= EOF) {
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      col++;
    }
  }

  // close file
  fclose(fp);

  // print results
  printf("Number of lines: %d\n", line);
  printf("Number of columns: %d\n", col);

  return 0;
}