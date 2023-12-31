#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int line = 1, col = 1;
  char ch;
  // prompt user for filename
  char filename[100];
  printf("Enter filename: ");
  scanf("%99s", filename); // Added field width limit of 99 to prevent crashes
  // open file in read mode
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  // read and print contents of file character by character
  printf("Contents of file:\n");
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