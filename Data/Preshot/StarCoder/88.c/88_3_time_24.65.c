#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Verify that the program is being called with the correct number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    return 1;
  }

  // Allocate memory for the destination string
  int len = strlen(argv[1]);
  char *d = malloc(len + 1);
  if (d == NULL) {
    fprintf(stderr, "Failed to allocate memory for destination string.\n");
    return 1;
  }

  // Copy the source string to the destination string using strncpy
  if (strncpy(d, argv[1], len + 1) == NULL) {
    fprintf(stderr, "Failed to copy source string to destination string.\n");
    free(d);
    return 1;
  }

  // Print the result and free the allocated memory
  printf("d = %s\n", d);
  free(d);
  return 0;
}