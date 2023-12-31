#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  if (argc != 2) {
    printf("Please provide exactly one argument.\n");
    return 1;
  }

  int len = strlen(argv[1]);
  char *d = malloc(len + 1);
  if (d == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  int result = strncpy_s(d, len + 1, argv[1], len);
  if (result != 0) {
    printf("Copying failed.\n");
    free(d);
    return 1;
  }

  printf("d = %s\n", d);
  free(d);
  return 0;
}