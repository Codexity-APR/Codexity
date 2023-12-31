#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);
    if (argc < 2) {
        printf("No argument specified\n");
        // Add code to handle this case
        // For example, you can assign a default directory or prompt the user for input
        // Here, I'm assigning a default directory "default_dir"
        strcpy(dir, "default_dir");
    } else {
        strcpy(dir, argv[1]);
    }
    return dir;
}

int main(int argc, char *argv[]) {
    char* dir = handle_input(argc, argv);
    // Rest of the code goes here
    free(dir);
    return 0;
}