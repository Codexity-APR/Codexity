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
    if (list->size >= list->capacity) {
        if (list->capacity == 0) {
            list->capacity = 1;
        }
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (list->arr == NULL) {
            return -1;
        }
    }
    list->arr[list->size] = value;
    list->size++;
    return 0;
}

int list_get(List *list, int index) {
    if (index >= list->size) {
        return -1;
    }
    return list->arr[index];
}

int list_remove(List *list, int index) {
    if (index >= list->size) {
        return -1;
    }
    int i;
    for (i = index; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
    if (list->size <= list->capacity / 4) {
        list->capacity /= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (list->arr == NULL && list->capacity > 0) {
            return -1;
        }
    }
    return 0;
}

int main() {
    List *list = list_new();
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);
    printf("%d\n", list_get(list, 0));
    printf("%d\n", list_get(list, 1));
    printf("%d\n", list_get(list, 2));
    list_remove(list, 1);
    printf("%d\n", list_get(list, 0));
    printf("%d\n", list_get(list, 1));
    printf("%d\n", list_get(list, 2));
    list_free(list);
    return 0;
}