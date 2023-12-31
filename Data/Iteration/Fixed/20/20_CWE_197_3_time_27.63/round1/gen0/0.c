#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *ptr;
  ptr = fopen("D:\\f4.txt", "r+");
  if (ptr == NULL) {
    printf("File couldn't be opened");
    exit(0);
  }
  int ch = fgetc(ptr);
  while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(ptr);
  }
  fclose(ptr);
  return 0;
}