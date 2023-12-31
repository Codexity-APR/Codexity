#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  int len = strlen(argv[1]);
  char *d = malloc (strlen(argv[1]) + 1);

  if (d == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  strcpy(d, argv[1]);

  printf("The argument you entered is: %s\n", d);

  free(d);

  return 0;
}