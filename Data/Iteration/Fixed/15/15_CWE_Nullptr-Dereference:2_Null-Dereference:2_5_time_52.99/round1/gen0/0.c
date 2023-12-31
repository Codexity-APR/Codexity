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
    list->capacity = 10;
    list->size = 0;
    list->arr = (int *) malloc(list->capacity * sizeof(int));
    if (list->arr == NULL) {
        free(list);
        return NULL;
    }
    return list;
}

void list_free(List *list) {
    if (list == NULL) {
        return;
    }
    free(list->arr);
    free(list);
}

void list_add(List *list, int element) {
    if (list == NULL) {
        return;
    }
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        int *newArr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (newArr == NULL) {
            return;
        }
        list->arr = newArr;
    }
    list->arr[list->size++] = element;
}

int main() {
    List *myList = list_new();
    if (myList == NULL) {
        return 1;
    }
    list_add(myList, 5);
    list_add(myList, 10);
    list_add(myList, 15);
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->arr[i]);
    }
    list_free(myList);
    return 0;
}