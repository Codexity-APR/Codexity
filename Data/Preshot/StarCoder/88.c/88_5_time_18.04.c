#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char* d = NULL;

  if (argc == 2 && argv[1] != NULL) {
    size_t len = strlen(argv[1]);
    d = malloc(len + 1);
  
    if (d != NULL) {
      // Use strncpy() instead of strcpy() to avoid buffer overflow
      strncpy(d, argv[1], len);
      d[len] = '\0';
      printf("d = %s\n", d);
      free(d);
      return 0;
    }
  }
  printf("Invalid arguments\n");
  return 1;
}