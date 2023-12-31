#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check if argument exists
  if (argc < 2) {
    printf("Please enter a valid argument.\n");
    return 1;
  }

  // Assume 1 arg only
  int len = strlen(argv[1]);
  char *d = malloc (len + 1);
  if (!d) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  strncpy(d, argv[1], len);
  d[len] = '\0';

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