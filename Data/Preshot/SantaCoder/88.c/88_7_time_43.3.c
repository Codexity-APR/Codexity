#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  if (argc != 2) {
    printf("Usage: %s <input_string>\n", argv[0]);
    return 1;
  }

  int len = strlen(argv[1]);
  char *d = malloc (len+1);
  if (!d) {
    printf("Memory allocation failed\n");
    return 1;
  }
  strcpy(d, argv[1]);
  char *p = d + len - 1;

  while (p >= d) {
    printf("%c", *p);
    p--;
  }

  free(d);
  return 0;
}