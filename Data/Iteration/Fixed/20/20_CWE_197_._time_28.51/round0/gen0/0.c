#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * ptr;
  ptr = fopen("D:\\f4.txt", "r+");

  if (ptr == NULL) {
    printf("file cant be opened");
    exit(0);
  }

  char ch = fgetc(ptr);

  while (ch != EOF) {
    // Code logic for processing each character
    printf("%c", ch);
    ch = fgetc(ptr);
  }

  fclose(ptr);

  return 0;
}