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

void list_add(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value;
    list->size++;
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int main() {
    List *myList = list_new();
    list_add(myList, 10);
    list_add(myList, 20);
    list_add(myList, 30);

    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->arr[i]);
    }
    
    list_free(myList);
    
    return 0;
}