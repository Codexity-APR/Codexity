#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }
    list->arr = NULL;
    list->capacity = 0;
    list->size = 0;

    return list;
}

void list_free(List *list) {
    if (list->arr != NULL) {
        free(list->arr);
    }

    free(list);
}