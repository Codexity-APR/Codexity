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
        int new_capacity = list->capacity == 0 ? 1 : list->capacity * 2;
        int *new_arr = (int *) realloc(list->arr, new_capacity * sizeof(int));
        if (new_arr == NULL) {
            printf("Error: Out of memory\n");
            return;
        }
        list->arr = new_arr;
        list->capacity = new_capacity;
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
    list_add(list, 5);
    list_add(list, 10);
    list_add(list, 15);
    list_print(list);
    list_free(list);
    return 0;
}