#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
        printf("No argument specified\n");
        return NULL;
    }

    strncpy(dir, argv[1], 200);
    dir[199] = '\0';
    return dir;
}

int main(int argc, char *argv[]) {
    char* directory = handle_input(argc, argv);
    if (directory == NULL) {
        printf("Exiting program\n");
        return 0;
    }
    
    // Rest of the code
    // ...

    free(directory);
    return 0;
}