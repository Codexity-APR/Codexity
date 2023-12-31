#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check that we have at least one argument
  if (argc < 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  // Allocate memory for the destination string
  int len = strlen(argv[1]);
  char *d = malloc(len + 1);
  if (d == NULL) {
    printf("Error: Failed to allocate memory.\n");
    return 1;
  }

#ifdef FOO
  // BAD: strcpy() is inherently insecure
  strcpy(d, argv[1]);
#else
  // GOOD: strncpy() is safer
  strncpy(d, argv[1], len);
#endif

  printf("d = %s\n", d);

  // Free the allocated memory
  free(d);

  return 0;
}