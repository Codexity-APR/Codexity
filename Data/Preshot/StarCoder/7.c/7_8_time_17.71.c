#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* handle_input(int argc, char *argv[]) {
    if (argc < 2) {
       printf("No argument specified\n");
       return NULL;
    }
    char* dir = strdup(argv[1]); // dynamically allocate memory and copy argument to dir
    return dir;
}

int main(int argc, char *argv[]) {
    char* dir = handle_input(argc, argv);
    if (dir == NULL) {
        printf("No directory specified\n");
        return 1;
    }
    printf("Directory: %s\n", dir);
    free(dir); // free the dynamically allocated memory
    return 0;
}