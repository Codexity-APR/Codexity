#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = NULL;
    if (argc < 2) {
       printf("No argument specified\n");
       return NULL;
    } else if (argc > 2) {
       printf("Too many arguments\n");
       return NULL;
    } else {
       dir = malloc(200);
       printf("Number of arguments: %d\n", argc);
       // other code for handling input
    }
    return dir;
}

int main(int argc, char *argv[]) {
    char* dir = handle_input(argc, argv);
    if (dir != NULL) {
        // do something with dir
        free(dir);
    }
    return 0;
}