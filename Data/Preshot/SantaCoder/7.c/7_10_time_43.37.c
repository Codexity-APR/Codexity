#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = NULL;
    
    if (argc < 2) {
        printf("No argument specified\n");
        return dir;
    }
    
    if (argc > 2) {
        printf("Too many arguments\n");
        return dir;
    }
    
    dir = malloc(200);
    if (dir == NULL) {
        printf("Memory allocation failed\n");
        return dir;
    }
    
    // Copy the argument to dir
    strcpy(dir, argv[1]);
    
    return dir;
}