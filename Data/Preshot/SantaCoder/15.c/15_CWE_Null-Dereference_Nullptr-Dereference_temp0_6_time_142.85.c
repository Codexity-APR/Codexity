#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    list->arr = NULL;
    list->capacity = 0;
    list->size = 0;
    return list;
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int list_append(List *list, int value) {
    if (list->size == list->capacity) {
        int new_capacity = list->capacity == 0 ? 1 : list->capacity * 2;
        int *new_arr = (int *) realloc(list->arr, new_capacity * sizeof(int));
        if (new_arr == NULL) {
            return -1;
        }
        list->arr = new_arr;
        list->capacity = new_capacity;
    }
    list->arr[list->size] = value;
    list->size++;
    return 0;
}

int list_get(List *list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    return list->arr[index];
}

int list_set(List *list, int index, int value) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    list->arr[index] = value;
    return 0;
}

int list_insert(List *list, int index, int value) {
    if (index < 0 || index > list->size) {
        return -1;
    }
    if (list->size == list->capacity) {
        int new_capacity = list->capacity == 0 ? 1 : list->capacity * 2;
        int *new_arr = (int *) realloc(list->arr, new_capacity * sizeof(int));
        if (new_arr == NULL) {
            return -1;
        }
        list->arr = new_arr;
        list->capacity = new_capacity;
    }
    int i;
    for (i = list->size - 1; i >= index; i--) {
        list->arr[i + 1] = list->arr[i];
    }
    list->arr[index] = value;
    list->size++;
    return 0;
}

int list_remove(List *list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    int i;
    for (i = index; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
    return 0;
}

int list_size(List *list) {
    return list->size;
}