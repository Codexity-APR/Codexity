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
    if (list->arr) {
        free(list->arr);
    }
    free(list);
}

int list_append(List *list, int value) {
    if (list->size == list->capacity) {
        if (list->capacity == 0) {
            list->capacity = 1;
        } else {
            list->capacity *= 2;
        }
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size++] = value;
    return 0;
}

int list_get(List *list, int index) {
    if (index >= 0 && index < list->size) {
        return list->arr[index];
    }
    return -1;
}

void list_print(List *list) {
    int i;
    printf("[");
    for (i = 0; i < list->size; i++) {
        printf("%d", list->arr[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    List *list = list_new();
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);
    list_print(list);
    list_free(list);
    return 0;
}