#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * ptr = NULL;
  char ch = '\0';

  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("File cannot be opened\n");
    exit(1);
  }

  ch = fgetc(ptr);
  printf("%c\n", ch);

  fclose(ptr);

  return 0;
}