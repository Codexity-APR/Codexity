#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    if (list != NULL) {
        list->arr = NULL;
        list->capacity = 0;
        list->size = 0;
    }
    return list;
}

void list_add(List *list, int element) {
    if (list != NULL) {
        if (list->size >= list->capacity) {
            list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
            list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        }
        if (list->arr != NULL) {
            list->arr[list->size] = element;
            list->size++;
        }
    }
}

void list_print(List *list) {
    if (list != NULL) {
        printf("[");
        for (int i = 0; i < list->size; i++) {
            printf("%d", list->arr[i]);
            if (i != list->size - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main() {
    List *list = list_new();
    if (list != NULL) {
        list_add(list, 1);
        list_add(list, 2);
        list_add(list, 3);
        list_print(list);
        free(list->arr);
        free(list);
    }
    return 0;
}