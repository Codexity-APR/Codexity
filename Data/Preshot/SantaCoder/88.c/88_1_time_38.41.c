#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Assume 1 arg only
  if(argc < 2){
    printf("Please provide a string argument\n");
    exit(1);
  }
  int len = strlen(argv[1]);
  char *d = malloc (len + 1);
  if(d == NULL){
      printf("Memory allocation failed\n");
      exit(1);
  }
  char *p = d;
  memcpy(d, argv[1], len + 1);
  
  while (len--) {
    p = strchr(p, argv[1][len]);
  }
  free(d);
  return 0;
}