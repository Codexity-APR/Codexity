#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    return 1;
  }

  int len = strlen(argv[1]);
  char *d = malloc(len + 1);
  if (d == NULL) {
    fprintf(stderr, "Failed to allocate memory!\n");
    return 1;
  }
  strcpy(d, argv[1]);

#ifdef __cplusplus
  char *p = d;
#else
  char *p = d + 1;
#endif

  while (len--) {
    p = strchr(p, argv[1][len]);
  }

  free(d);
  return 0;
}