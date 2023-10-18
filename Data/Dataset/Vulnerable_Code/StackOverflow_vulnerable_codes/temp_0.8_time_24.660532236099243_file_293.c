#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
        printf("No argument specified\n");
    }
    else {
        strcpy(dir, argv[1]);
        printf("Directory: %s\n", dir);
    }

    return dir;
}

int main(int argc, char *argv[]) {
    char* result = handle_input(argc, argv);
    // Add your code here

    free(result);
    return 0;
}