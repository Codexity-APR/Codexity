#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * ptr;
  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("Unable to open file");
    return 1;
  }

  char ch = fgetc(ptr);
  printf("%c\n", ch);

  fclose(ptr);
  return 0;
}