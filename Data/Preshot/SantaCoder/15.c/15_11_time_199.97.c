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
    list->arr = (int *)malloc(list->capacity * sizeof(int));
    return list;
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int list_append(List *list, int val) {
    if (list->size >= list->capacity) {
        return -1;
    }
    list->arr[list->size++] = val;
    return 0;
}

int list_append_back(List *list, int val) {
    if (list->size >= list->capacity) {
        return -1;
    }
    int i;
    for (i = list->size; i > 0; i--) {
        list->arr[i] = list->arr[i-1];
    }
    list->arr[0] = val;
    list->size++;
    return 0;
}

int list_insert(List *list, int val, int index) {
    if (list->size >= list->capacity) {
        return -1;
    }
    int i;
    for (i = list->size; i > index; i--) {
        list->arr[i] = list->arr[i-1];
    }
    list->arr[index] = val;
    list->size++;
    return 0;
}

int list_insert_back(List *list, int val, int index) {
    if (list->size >= list->capacity) {
        return -1;
    }
    list->arr[list->size++] = val;
    return 0;
}

int list_remove(List *list, int index) {
    int i;
    for (i = index; i < list->size-1; i++) {
        list->arr[i] = list->arr[i+1];
    }
    list->size--;
    return 0;
}

int list_remove_front(List *list) {
    int i;
    for (i = 0; i < list->size-1; i++) {
        list->arr[i] = list->arr[i+1];
    }
    list->size--;
    return 0;
}

int list_remove_back(List *list) {
    list->size--;
    return 0;
}

void list_print(List *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int main() {
    List *list = list_new();
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    list_append(list, 40);
    list_print(list);

    list_insert(list, 15, 1);
    list_print(list);

    list_remove(list, 2);
    list_print(list);

    list_remove_front(list);
    list_print(list);

    list_remove_back(list);
    list_print(list);

    list_insert_back(list, 25);
    list_print(list);

    list_append_back(list, 35);
    list_print(list);

    list_free(list);
    return 0;
}