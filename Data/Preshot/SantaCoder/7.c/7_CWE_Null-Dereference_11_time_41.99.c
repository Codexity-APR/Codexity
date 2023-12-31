#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
        printf("No argument specified\n");
        free(dir);
        dir = NULL;
        return dir;
    }

    if (argc > 2) {
        printf("Too many arguments\n");
        free(dir);
        dir = NULL;
        return dir;
    }

    // Handle the case where argc == 2
    // Copy the second argument to dir
    strcpy(dir, argv[1]);
    return dir;
}