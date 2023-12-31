#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check if there is an argument provided
  if (argc != 2) {
    printf("Usage: %s <argument>\n", argv[0]);
    return 1;
  }

  // Allocate memory for the destination string
  size_t len = strlen(argv[1]);
  char *d = malloc (len + 1);
  if (d == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }

  // Copy the argument to the destination string
  strncpy(d, argv[1], len);
  d[len] = '\0';

  printf("d = %s\n", d);

  // Free the memory
  free(d);

  return 0;
}