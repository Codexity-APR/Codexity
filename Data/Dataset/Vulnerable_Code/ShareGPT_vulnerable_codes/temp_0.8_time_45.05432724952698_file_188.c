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

void list_add(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
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
    List *list = list_new();
    
    // Add some values to the list
    list_add(list, 5);
    list_add(list, 10);
    list_add(list, 15);
    
    // Print the values in the list
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    
    // Free the memory allocated for the list
    list_free(list);
    
    return 0;
}