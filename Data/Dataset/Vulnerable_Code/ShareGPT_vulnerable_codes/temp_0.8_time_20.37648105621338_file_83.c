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
    printf("Cannot open file.\n");
    return 1;
  }

  // read and print the content of the file
  printf("Content of the file:\n");
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  // close the file
  fclose(fp);

  return 0;
}