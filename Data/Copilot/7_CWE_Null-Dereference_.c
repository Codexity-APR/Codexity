#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    char* dir = malloc(200);
    printf("Number of arguments: %d\n", argc);

    if (argc < 2) {
       printf("No argument specified\n");
       exit(1);
    }
    else {
        strcpy(dir, argv[1]);
        printf("Directory specified: %s\n", dir);
    }
    return dir;
}

int main(int argc, char *argv[]) {
    char* dir = handle_input(argc, argv);
    // rest of the code goes here
    free(dir);
    return 0;
}
