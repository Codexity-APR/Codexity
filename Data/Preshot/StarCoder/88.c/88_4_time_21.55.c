#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if(argc < 2){
    printf("Usage: %s <input_string>\n", argv[0]);
    return 1;
  }

  int len = strlen(argv[1]);
  char *d = malloc(len + 1);

  if(d == NULL){
    printf("Error: Unable to allocate memory\n");
    return 1;
  }

  strncpy(d, argv[1], len);
  d[len] = '\0';

  printf("d = %s\n", d);

  free(d);
  return 0;
}