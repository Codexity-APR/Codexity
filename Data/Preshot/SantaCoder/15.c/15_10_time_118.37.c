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
        return NULL;
    }
    list->arr = NULL;
    list->capacity = 0;
    list->size = 0;
    return list;
}

void list_free(List *list) {
    if (list == NULL) {
        return;
    }
    free(list->arr);
    free(list);
}

int list_append(List *list, int val) {
    if (list == NULL) {
        return -1;
    }
    if (list->capacity == list->size) {
        int new_capacity = list->capacity == 0 ? 1 : 2 * list->capacity;
        int *new_arr = (int *) realloc(list->arr, new_capacity * sizeof(int));
        if (new_arr == NULL) {
            return -1;
        }
        list->arr = new_arr;
        list->capacity = new_capacity;
    }
    list->arr[list->size++] = val;
    return 0;
}

int list_get(List *list, int index, int *val) {
    if (list == NULL || index < 0 || index >= list->size) {
        return -1;
    }
    *val = list->arr[index];
    return 0;
}

int list_set(List *list, int index, int val) {
    if (list == NULL || index < 0 || index >= list->size) {
        return -1;
    }
    list->arr[index] = val;
    return 0;
}

int list_size(List *list) {
    if (list == NULL) {
        return -1;
    }
    return list->size;
}

int list_capacity(List *list) {
    if (list == NULL) {
        return -1;
    }
    return list->capacity;
}