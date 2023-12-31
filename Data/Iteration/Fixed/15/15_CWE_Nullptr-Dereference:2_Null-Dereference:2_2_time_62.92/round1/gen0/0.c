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

void list_append(List *list, int value) {
    if (list == NULL || list->arr == NULL) {
        return;
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (list->arr == NULL) {
            return;
        }
    }
    list->arr[list->size++] = value;
}

void list_print(List *list) {
    if (list == NULL || list->arr == NULL) {
        return;
    }
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void list_free(List *list) {
    if (list == NULL || list->arr == NULL) {
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