#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * ptr;
  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("file cant be opened");
    return 1;
  }

  char ch = fgetc(ptr);
  
  fclose(ptr);
  
  printf("%c\n", ch);

  return 0;
}