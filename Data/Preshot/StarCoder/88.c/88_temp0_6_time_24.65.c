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
  if (d == NULL) {
    printf("Error: Failed to allocate memory\n");
    return 1;
  }

#ifdef FOO
  // BAD: strcpy() is inherently insecure
  strcpy(d, argv[1]);
#else
  // GOOD: strncpy() is safer
  strncpy(d, argv[1], len);
  d[len] = '\0';
#endif

  printf("d = %s\n", d);
  free(d);
  return 0;
}