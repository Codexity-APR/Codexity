#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * ptr;
  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("File cannot be opened.\n");
    exit(1);
  }

  char ch = fgetc(ptr);
  
  while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(ptr);
  }
  
  fclose(ptr);
  
  return 0;
}