#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
        printf("No argument specified\n");
        free(dir);
        return;
    }

    if (argc > 2) {
        printf("Too many arguments\n");
        free(dir);
        return;
    }

    // Do something with dir
    // ...

    free(dir);
    return;
}