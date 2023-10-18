#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    list->capacity = 10; // Set initial capacity to 10
    list->size = 0; // Set initial size to 0
    list->arr = (int *) malloc(list->capacity * sizeof(int)); // Allocate memory for the array
    return list;
}

void list_add(List *list, int value) {
    if (list->size == list->capacity) {
        // If the list is full, double the capacity
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value; // Add the value to the end of the list
    list->size++; // Increment the size
}

void list_print(List *list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void list_free(List *list) {
    free(list->arr); // Free the memory allocated for the array
    free(list); // Free the memory allocated for the list
}

int main() {
    List *list = list_new(); // Create a new list

    // Add some values to the list
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);

    // Print the list
    list_print(list);

    // Free the memory allocated for the list
    list_free(list);

    return 0;
}