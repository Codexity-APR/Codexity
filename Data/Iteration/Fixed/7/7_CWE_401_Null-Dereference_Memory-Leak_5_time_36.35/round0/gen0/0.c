#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
       printf("No argument specified\n");
       return NULL; // Added return statement to handle the error case
    }

    strcpy(dir, argv[1]);
    return dir;
}

int main(int argc, char *argv[]) {
    char* directory = handle_input(argc, argv);

    if (directory == NULL) {
        printf("Exiting program\n");
        return 0; // Added return statement to exit the program gracefully
    }

    printf("Directory: %s\n", directory);

    free(directory); // Added memory deallocation

    return 0;
}