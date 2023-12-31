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
        printf("Memory allocation failed.\n");
        return NULL;
    }
    list->arr = (int *) malloc(sizeof(int));
    if (list->arr == NULL) {
        printf("Memory allocation failed.\n");
        free(list);
        return NULL;
    }
    list->capacity = 1;
    list->size = 0;
    return list;
}

void list_add(List *list, int value) {
    if (list->size == list->capacity) {
        int newCapacity = list->capacity * 2;
        int *newArr = (int *) realloc(list->arr, newCapacity * sizeof(int));
        if (newArr == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        list->arr = newArr;
        list->capacity = newCapacity;
    }
    list->arr[list->size] = value;
    list->size++;
}

void list_print(List *list) {
    printf("List: ");
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
    if (list == NULL) {
        return 1;
    }
    list_add(list, 10);
    list_add(list, 20);
    list_add(list, 30);
    list_print(list);
    list_free(list);
    return 0;
}