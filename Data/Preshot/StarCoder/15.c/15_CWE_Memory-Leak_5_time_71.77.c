#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int size;
} List;

List* list_new() {
    List* list = (List*) malloc(sizeof(List));
    if (list == NULL) {
        printf("Failed to allocate memory for list\n");
        return NULL;
    }

    list->arr = (int*) malloc(sizeof(int));
    if (list->arr == NULL) {
        printf("Failed to allocate memory for list's array\n");
        free(list);
        return NULL;
    }

    list->capacity = 1;
    list->size = 0;

    return list;
}

void list_add(List* list, int val) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    if (list->size == list->capacity) {
        list->capacity *= 2;
        int* new_arr = (int*) realloc(list->arr, list->capacity * sizeof(int));
        if (new_arr == NULL) {
            printf("Failed to reallocate memory for list's array\n");
            return;
        }
        list->arr = new_arr;
    }

    list->arr[list->size++] = val;
}

int list_get(List* list, int index) {
    if (list == NULL) {
        printf("List is NULL\n");
        return -1;
    }

    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    return list->arr[index];
}

void list_free(List* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    free(list->arr);
    free(list);
}

int main(int argc, char *argv[]) {
    List* list = list_new();
    if (list == NULL) {
        printf("Failed to create new list\n");
        return -1;
    }

    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    printf("%d\n", list_get(list, 1));

    list_free(list);

    return 0;
}