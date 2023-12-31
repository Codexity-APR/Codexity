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
    list->arr = (int *) malloc(sizeof(int));
    if (list->arr == NULL) {
        free(list);
        return NULL;
    }
    list->capacity = 1;
    list->size = 0;
    return list;
}

void list_add(List *list, int val) {
    if (list == NULL || list->arr == NULL) {
        return;
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        int *new_arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (new_arr == NULL) {
            return;
        }
        list->arr = new_arr;
    }
    list->arr[list->size++] = val;
}

int list_get(List *list, int index) {
    if (list == NULL || list->arr == NULL || index < 0 || index >= list->size) {
        return -1;
    }
    return list->arr[index];
}

void list_free(List *list) {
    if (list == NULL) {
        return;
    }
    free(list->arr);
    free(list);
}

int main(int argc, char *argv[]) {
    List *list = list_new();
    if (list == NULL) {
        return 1;
    }
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    printf("%d\n", list_get(list, 1));
    list_free(list);
    return 0;
}