#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_input(int argc, char *argv[], char **dir) {
    if (argc < 2) {
        printf("No argument specified\n");
        *dir = NULL;
    }
    else {
        *dir = malloc(strlen(argv[1]) + 1);
        strcpy(*dir, argv[1]);
    }
}

int main(int argc, char *argv[]) {
    char* dir = NULL;
    handle_input(argc, argv, &dir);
    if (dir == NULL) {
        printf("No directory specified\n");
        return 1;
    }
    printf("Directory: %s\n", dir);
    free(dir);
    return 0;
}