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
        list->arr = (int *) malloc(sizeof(int));
        if (list->arr) {
            list->capacity = 1;
            list->size = 0;
            return list;
        }
        free(list);
    }
    return NULL;
}

int list_add(List *list, int val) {
    if (list) {
        if (list->size == list->capacity) {
            int *new_arr = (int *) realloc(list->arr, list->capacity * 2 * sizeof(int));
            if (new_arr) {
                list->arr = new_arr;
                list->capacity *= 2;
            } else {
                return 0;
            }
        }
        list->arr[list->size++] = val;
        return 1;
    }
    return 0;
}

int list_get(List *list, int index) {
    if (list && index >= 0 && index < list->size) {
        return list->arr[index];
    }
    return -1;  // return -1 to indicate an error
}

void list_free(List *list) {
    if (list) {
        free(list->arr);
        free(list);
    }
}

int main(int argc, char *argv[]) {
    List *list = list_new();
    if (list) {
        if (list_add(list, 1)) {
            if (list_add(list, 2)) {
                if (list_add(list, 3)) {
                    printf("%d\n", list_get(list, 1));
                }
            }
        }
        list_free(list);
    }
    return 0;
}