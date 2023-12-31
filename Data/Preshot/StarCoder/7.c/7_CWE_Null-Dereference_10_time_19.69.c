#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = NULL;
    if (argc < 2) {
        printf("No argument specified\n");
    } else {
        dir = malloc(strlen(argv[1]) + 1);
        strcpy(dir, argv[1]);
    }
    return dir;
}

int main(int argc, char *argv[]) {
    char* dir = handle_input(argc, argv);
    if (dir == NULL) {
        printf("No directory specified\n");
        return 1;
    }
    printf("Directory: %s\n", dir);
    free(dir); // free the allocated memory
    return 0;
}