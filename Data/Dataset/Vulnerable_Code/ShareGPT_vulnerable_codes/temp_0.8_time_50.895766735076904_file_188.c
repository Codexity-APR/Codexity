#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    list->capacity = 10; // Default capacity
    list->arr = (int *) malloc(list->capacity * sizeof(int));
    list->size = 0;
    return list;
}

void list_append(List *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2; // Double the capacity if full
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value;
    list->size++;
}

void list_print(List *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int main() {
    List *list = list_new();
    
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    
    list_print(list);
    
    list_free(list);
    
    return 0;
}