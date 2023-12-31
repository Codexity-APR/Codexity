#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  int len = strlen(argv[1]);
  char *d = malloc (len + 1);
  if (d == NULL) {
    printf("Error: Memory allocation failed.");
    return -1;
  }
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