#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = NULL;
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
        printf("No argument specified\n");
        return NULL;
    }

    if (argc > 2) {
        printf("Too many arguments\n");
        return NULL;
    }

    dir = malloc(200);
    if (dir == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Do something with dir

    return dir;
}