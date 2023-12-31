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
    printf("Error opening file.\n");
    return 1;
  }

  // read and print each character from the file
  printf("\nFile content:\n");
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      col++;
    }
  }

  // close the file
  fclose(fp);

  // print total lines and columns
  printf("\n\nTotal Lines: %d\n", line);
  printf("Total Columns: %d\n", col);

  return 0;
}