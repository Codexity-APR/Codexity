#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  int len = strlen(argv[1]);
  char *d = malloc (strlen(argv[1])+1);

  // Check if memory allocation was successful
  if (d == NULL) {
    fprintf(stderr, "Memory allocation failed.");
    return 1;
  }

  // Copy the string from argv[1] to d
  strcpy(d, argv[1]);

  // Print the copied string
  printf("Copied string: %s\n", d);

  // Free the allocated memory
  free(d);

  return 0;
}