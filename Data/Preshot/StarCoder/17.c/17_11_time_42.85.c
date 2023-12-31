#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100

int main(int argc, char *argv[]) {
  FILE *fp;
  int line = 1, col = 1;
  char ch;

  // prompt user for filename
  char filename[MAX_FILENAME_SIZE];
  printf("Enter filename: ");

  // read filename from user input
  if (fgets(filename, MAX_FILENAME_SIZE, stdin) == NULL) {
    printf("Error reading filename\n");
    exit(1);
  }

  // remove newline character from filename
  size_t len = strlen(filename);
  if (len > 0 && filename[len-1] == '\n') {
    filename[len-1] = '\0';
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