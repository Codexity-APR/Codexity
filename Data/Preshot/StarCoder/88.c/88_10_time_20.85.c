#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  if (argc != 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  int len = strlen(argv[1]);
  char *d = malloc(len + 1);

  if (d == NULL) { // Null check for d pointer
    printf("Memory allocation failed\n");
    return 1;
  }

  strncpy(d, argv[1], len);
  d[len] = '\0'; // Ensuring null termination of the string

  printf("d = %s\n", d);
  free(d);
  return 0;
}