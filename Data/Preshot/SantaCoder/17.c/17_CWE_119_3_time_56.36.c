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
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // read file character by character
  while ((ch = fgetc(fp)) != EOF) {
    printf("%d:%d: %c\n", line, col, ch);
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