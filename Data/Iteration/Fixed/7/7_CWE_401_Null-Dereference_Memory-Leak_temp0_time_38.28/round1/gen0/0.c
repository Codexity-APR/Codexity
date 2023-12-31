#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No argument specified\n");
        return NULL;
    }
    
    char* dir = malloc(200);
    if (dir == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    printf("Number of arguments: %d\n", argc);
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
    
    // Rest of the code
    
    free(directory);
    return 0;
}