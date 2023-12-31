#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
       printf("No argument specified\n");
       return dir;
    }

    if (argc > 2) {
       printf("Too many arguments\n");
       free(dir);
       return NULL;
    }

    // Copy the argument to the dir variable
    strncpy(dir, argv[1], 199);
    dir[199] = '\0';

    return dir;
}