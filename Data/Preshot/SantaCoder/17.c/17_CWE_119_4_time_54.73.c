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
  fp = fopen(filename, "r"); // open the file in read mode
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // read file character by character
  while ((ch = fgetc(fp)) != EOF) {
    printf("%d:%d: %c\n", line, col, ch);
    if (ch == '\n') { // line break
      line++;
      col = 1;
    } else {
      col++;
    }
  }

  // close file
  fclose(fp);
  return 0;
}