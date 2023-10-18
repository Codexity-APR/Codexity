#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
        printf("No argument specified\n");
    } else {
        strncpy(dir, argv[1], 200);
        printf("Argument specified: %s\n", dir);
    }

    return dir;
}

int main(int argc, char *argv[]) {
    char* directory = handle_input(argc, argv);
    // Rest of your code goes here

    free(directory); // Don't forget to free the memory allocated
    return 0;
}