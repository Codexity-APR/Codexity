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

void list_append(List *list, int value) {
    if (list->arr == NULL) {
        list->capacity = 1;
        list->arr = (int *) malloc(list->capacity * sizeof(int));
    } else if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value;
    list->size++;
}

void list_print(List *list) {
    if (list->size == 0) {
        printf("List is empty.\n");
    } else {
        printf("List: ");
        for (int i = 0; i < list->size; i++) {
            printf("%d ", list->arr[i]);
        }
        printf("\n");
    }
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int main() {
    List *myList = list_new();

    list_append(myList, 10);
    list_append(myList, 20);
    list_append(myList, 30);

    list_print(myList);

    list_free(myList);

    return 0;
}