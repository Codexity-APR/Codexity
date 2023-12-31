#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  int len = strlen(argv[1]);
  char *d = malloc (len + 1);
  if (d == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  char *p = d;
  while (len--) {
    *p = argv[1][len];
    p++;
  }
  *p = '\0'; // Add null terminator to the string
  free(d); // Free allocated memory
  return 0;
}