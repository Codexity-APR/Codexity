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
        fprintf(stderr, "Memory allocation failed for List\n");
        return NULL;
    }
    list->capacity = 10;
    list->size = 0;
    list->arr = (int *) malloc(list->capacity * sizeof(int));
    if (list->arr == NULL) {
        fprintf(stderr, "Memory allocation failed for List array\n");
        free(list);
        return NULL;
    }
    return list;
}

void list_add(List *list, int element) {
    if (list == NULL) {
        fprintf(stderr, "Invalid List\n");
        return;
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        int *newArr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (newArr == NULL) {
            fprintf(stderr, "Memory allocation failed for List array\n");
            return;
        }
        list->arr = newArr;
    }
    list->arr[list->size++] = element;
}

void list_print(List *list) {
    if (list == NULL) {
        fprintf(stderr, "Invalid List\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

void list_free(List *list) {
    if (list == NULL) {
        fprintf(stderr, "Invalid List\n");
        return;
    }
    free(list->arr);
    free(list);
}

int main() {
    List *myList = list_new();
    if (myList == NULL) {
        fprintf(stderr, "Failed to create List\n");
        return 1;
    }
    list_add(myList, 10);
    list_add(myList, 20);
    list_add(myList, 30);
    list_print(myList);
    list_free(myList);
    return 0;
}