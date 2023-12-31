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
    else {
        dir = malloc(200);
        strcpy(dir, argv[1]);
        printf("Directory: %s\n", dir);
        return dir;
    }
}

int main(int argc, char *argv[]) {
    char* directory = handle_input(argc, argv);
    // Rest of the code
    free(directory);
    return 0;
}