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

void list_add(List *list, int item) {
    if (list == NULL) {
        return;
    }
    if (list->capacity == 0) {
        list->capacity = 1;
        list->arr = (int *) malloc(sizeof(int) * list->capacity);
        if (list->arr == NULL) {
            return;
        }
    } else if (list->size == list->capacity) {
        list->capacity *= 2;
        int *temp = (int *) realloc(list->arr, sizeof(int) * list->capacity);
        if (temp == NULL) {
            return;
        }
        list->arr = temp;
    }
    list->arr[list->size] = item;
    list->size++;
}

void list_free(List *list) {
    if (list == NULL) {
        return;
    }
    free(list->arr);
    free(list);
}

int main() {
    List *myList = list_new();
    if (myList == NULL) {
        return 1;
    }
    list_add(myList, 10);
    list_add(myList, 20);
    list_add(myList, 30);
    for (int i = 0; i < myList->size; i++) {
        if (myList->arr != NULL && i < myList->size) {
            printf("%d ", myList->arr[i]);
        }
    }
    list_free(myList);
    return 0;
}