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
    printf("Unable to open file.\n");
    return 1;
  }

  // read and print contents of file
  printf("\nFile Contents:\n\n");
  printf("Line %d: ", line);
  
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
    col++;
    if (ch == '\n') {
      line++;
      col = 1;
      printf("Line %d: ", line);
    }
  }

  // close file
  fclose(fp);

  return 0;
}