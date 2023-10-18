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
    printf("Error opening file!\n");
    exit(1);
  }

  // read and print the file character by character
  printf("\nFile Contents:\n");
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
    
    // update line and column count
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      col++;
    }
  }

  // close the file
  fclose(fp);

  // print line and column count
  printf("\n\nLine: %d\n", line);
  printf("Column: %d\n", col);

  return 0;
}