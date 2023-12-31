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
        if (list->capacity == 0) {
            list->capacity = 1;
        } else {
            list->capacity *= 2;
        }
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value;
    list->size++;
}

void list_print(List *list) {
    printf("List: [");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->arr[i]);
        if (i != list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
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
    list_add(myList, 40);

    list_print(myList);

    list_free(myList);

    return 0;
}