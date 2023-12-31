#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  int len = strlen(argv[1]);
  char *d = malloc(len + 1);
  if (d == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  char *p = d;
  while (len--) {
    p = strchr(p, argv[1][len]);
    if (p == NULL) {
      fprintf(stderr, "%c not found in %s\n", argv[1][len], argv[1]);
      exit(EXIT_FAILURE);
    }
  }
  free(d);
  return 0;
}