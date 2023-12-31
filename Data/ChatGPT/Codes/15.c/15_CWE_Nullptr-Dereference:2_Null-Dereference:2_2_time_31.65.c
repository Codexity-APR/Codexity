#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    list->capacity = 10;
    list->size = 0;
    list->arr = (int *) malloc(list->capacity * sizeof(int));
    return list;
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

void list_add(List *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size++] = element;
}

int main() {
    List *myList = list_new();
    
    list_add(myList, 5);
    list_add(myList, 10);
    list_add(myList, 15);
    
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->arr[i]);
    }
    
    list_free(myList);
    
    return 0;
}