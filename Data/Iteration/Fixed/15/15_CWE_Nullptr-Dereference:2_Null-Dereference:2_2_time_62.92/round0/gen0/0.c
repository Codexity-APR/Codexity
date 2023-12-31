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

void list_append(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size++] = value;
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
    List *myList = list_new();
    
    // Append values to the list
    list_append(myList, 10);
    list_append(myList, 20);
    list_append(myList, 30);
    
    // Print the list
    list_print(myList);
    
    // Free the memory allocated for the list
    list_free(myList);
    
    return 0;
}