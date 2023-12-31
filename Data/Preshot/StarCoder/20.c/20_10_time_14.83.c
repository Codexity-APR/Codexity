#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *ptr;
  char ch;
  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("File cannot be opened.\n");
    return 1;
  }

  ch = fgetc(ptr);
  printf("The first character in the file is %c\n", ch);
  
  fclose(ptr);
  return 0;
}