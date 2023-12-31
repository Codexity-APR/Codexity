#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * ptr;
  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("File cannot be opened");
    exit(0);
  }

  char ch = fgetc(ptr);

  // Rest of the code goes here

  fclose(ptr);
  
  return 0;
}