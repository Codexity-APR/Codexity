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

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int list_append(List *list, int value) {
    if (list->size >= list->capacity) {
        int new_capacity = list->capacity == 0 ? 1 : 2 * list->capacity;
        int *new_arr = (int *) realloc(list->arr, new_capacity * sizeof(int));
        if (new_arr == NULL) {
            return -1;
        }
        list->arr = new_arr;
        list->capacity = new_capacity;
    }
    list->arr[list->size] = value;
    list->size++;
    return 0;
}

int main() {
    List *my_list = list_new();
    list_append(my_list, 1);
    list_append(my_list, 2);
    list_append(my_list, 3);
    for (int i = 0; i < my_list->size; i++) {
        printf("%d ", my_list->arr[i]);
    }
    printf("\n");
    list_free(my_list);
    return 0;
}