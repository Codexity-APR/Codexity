#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }
    list->arr = malloc(sizeof(int));
    if (!list->arr) {
        free(list);
        return NULL;
    }
    list->capacity = 1;
    list->size = 0;
    return list;
}

void list_add(List *list, int val) {
    if (!list) {
        return;
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        int *new_arr = realloc(list->arr, list->capacity * sizeof(int));
        if (!new_arr) {
            return;
        }
        list->arr = new_arr;
    }
    list->arr[list->size++] = val;
}

int list_get(List *list, int index) {
    if (!list || index < 0 || index >= list->size) {
        return -1;
    }
    return list->arr[index];
}

void list_free(List *list) {
    if (!list) {
        return;
    }
    free(list->arr);
    free(list);
}

int main(int argc, char *argv[]) {
    List *list = list_new();
    if (!list) {
        return 1;
    }
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    printf("%d\n", list_get(list, 1));
    list_free(list);
    return 0;
}