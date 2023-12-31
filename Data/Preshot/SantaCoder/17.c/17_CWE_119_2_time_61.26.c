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

  // open file for reading
#ifdef __cplusplus
  fp = fopen(filename, "r");
#else
  fp = fopen(filename, "r", 0);
#endif
  if (!fp) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  // read file character by character
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      line++;
      col = 1;
    } else {
      printf("%d:%d: %c\n", line, col, ch);
      col++;
    }
  }

  // close file
  fclose(fp);
  return 0;
}