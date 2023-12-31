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

  // open file in read mode
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // read file character by character
  while ((ch = fgetc(fp)) != EOF) {
    // check for new line
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      col++;
    }

    // print character and its position
    printf("Character: %c\tLine: %d\tColumn: %d\n", ch, line, col);
  }

  // close the file
  fclose(fp);

  return 0;
}