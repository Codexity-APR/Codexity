#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *ptr;
  char ch;

  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("File cannot be opened");
    exit(1);
  }

  ch = fgetc(ptr);

  fclose(ptr);
  
  return 0;
}