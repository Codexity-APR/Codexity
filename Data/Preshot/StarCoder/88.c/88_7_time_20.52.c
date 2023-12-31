#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  // Assume 1 arg only
  size_t len = strlen(argv[1]);
  char *d = malloc(len + 1);
  if (d == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }

  printf("Copying %zu bytes from argv[1] to d...\n", len);
  memcpy(d, argv[1], len);
  d[len] = '\0';

  printf("d = %s\n", d);
  free(d);
  return 0;
}