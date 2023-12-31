#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    if (list) {
        list->arr = NULL;
        list->capacity = 0;
        list->size = 0;
    }
    return list;
}

void list_free(List *list) {
    if (list) {
        free(list->arr);
        free(list);
    }
}

int list_append(List *list, int item) {
    if (list->size >= list->capacity) {
        int *new_arr = realloc(list->arr, (list->capacity + 1) * sizeof(int));
        if (!new_arr) return -1;
        list->arr = new_arr;
        list->capacity++;
    }
    list->arr[list->size] = item;
    list->size++;
    return 0;
}

int list_insert(List *list, int item, int index) {
    if (index < 0 || index > list->size) return -1;
    if (list->size >= list->capacity) {
        int *new_arr = realloc(list->arr, (list->capacity + 1) * sizeof(int));
        if (!new_arr) return -1;
        list->arr = new_arr;
        list->capacity++;
    }
    int i;
    for (i = list->size; i > index; i--) {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[index] = item;
    list->size++;
    return 0;
}

int list_remove(List *list, int index) {
    if (index < 0 || index >= list->size) return -1;
    int i;
    for (i = index; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
    return 0;
}

int list_remove_first(List *list, int item) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (list->arr[i] == item) {
            list_remove(list, i);
            return 0;
        }
    }
    return -1;
}

int list_remove_all(List *list, int item) {
    int i, count = 0;
    for (i = 0; i < list->size; i++) {
        if (list->arr[i] == item) {
            list_remove(list, i);
            count++;
            i--;
        }
    }
    return count;
}

int list_get(List *list, int index) {
    if (index < 0 || index >= list->size) return -1;
    return list->arr[index];
}

int list_set(List *list, int item, int index) {
    if (index < 0 || index >= list->size) return -1;
    list->arr[index] = item;
    return 0;
}

int list_size(List *list) {
    return list->size;
}

int list_capacity(List *list) {
    return list->capacity;
}