#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int line = 1, col = 1;
  char ch;
  // prompt user for filename
  char filename[100];
  printf("Enter filename: ");
  scanf("%99s", filename); // Added field width limit of 99 for filename
  // open file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Failed to open file.\n");
    return 1;
  }
  // read and print the content of the file
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
  return 0;
}