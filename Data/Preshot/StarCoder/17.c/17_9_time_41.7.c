#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100

int main(int argc, char *argv[]) {
  FILE *fp;
  int line = 1, col = 1;
  char ch;

  // prompt user for filename
  char filename[MAX_FILENAME_LENGTH];
  printf("Enter filename: ");

  // use fgets to read input and limit the number of characters read to MAX_FILENAME_LENGTH - 1
  if (fgets(filename, MAX_FILENAME_LENGTH, stdin) == NULL) {
    printf("Error reading input\n");
    exit(1);
  }

  // remove newline character from input, if present
  char *pos;
  if ((pos = strchr(filename, '\n')) != NULL) {
    *pos = '\0';
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