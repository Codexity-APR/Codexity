#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = NULL; // Initialize dir to NULL
    printf("Number of arguments: %d\n", argc);
    if (argc < 2) {
       printf("No argument specified\n");
       return dir; // Return NULL directly
    }
    dir = malloc(200);
    if (dir == NULL) {
        printf("Memory allocation failed\n");
        return dir; // Return NULL if memory allocation fails
    }
    strcpy(dir, argv[1]);
    return dir;
}

int main(int argc, char *argv[]) {
    char* directory = handle_input(argc, argv);
    if (directory == NULL) {
        printf("Exiting program\n");
        return 0;
    }
    printf("Directory: %s\n", directory);
    free(directory);
    return 0;
}