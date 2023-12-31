#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = (List *) malloc(sizeof(List));
    list->capacity = 10; // default capacity
    list->arr = (int *) malloc(sizeof(int) * list->capacity);
    list->size = 0;
    return list;
}

void list_free(List *list) {
    free(list->arr);
    free(list);
}

int list_append(List *list, int value) {
    if (list->size == list->capacity) {
        // double the capacity if list is full
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, sizeof(int) * list->capacity);
    }
    list->arr[list->size++] = value;
    return 0;
}

int list_append_back(List *list, int value) {
    if (list->size == list->capacity) {
        // double the capacity if list is full
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, sizeof(int) * list->capacity);
    }
    int i;
    for (i = list->size; i > 0; i--) {
        list->arr[i] = list->arr[i-1];
    }
    list->arr[0] = value;
    list->size++;
    return 0;
}

int list_insert(List *list, int value, int index) {
    if (index < 0 || index >= list->size) {
        // index out of bounds
        return -1;
    }
    if (list->size == list->capacity) {
        // double the capacity if list is full
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, sizeof(int) * list->capacity);
    }
    int i;
    for (i = list->size; i > index; i--) {
        list->arr[i] = list->arr[i-1];
    }
    list->arr[index] = value;
    list->size++;
    return 0;
}

int list_insert_back(List *list, int value, int index) {
    if (index < 0 || index >= list->size) {
        // index out of bounds
        return -1;
    }
    if (list->size == list->capacity) {
        // double the capacity if list is full
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, sizeof(int) * list->capacity);
    }
    int i;
    for (i = index; i < list->size; i++) {
        list->arr[i] = list->arr[i+1];
    }
    list->arr[list->size - 1] = value;
    list->size++;
    return 0;
}

int list_remove(List *list, int index) {
    if (index < 0 || index >= list->size) {
        // index out of bounds
        return -1;
    }
    int i;
    for (i = index; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i+1];
    }
    list->size--;
    return 0;
}

int list_remove_front(List *list) {
    if (list->size == 0) {
        // list is empty
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i+1];
    }
    list->size--;
    return 0;
}

int list_remove_back(List *list) {
    if (list->size == 0) {
        // list is empty
        return -1;
    }
    list->size--;
    return 0;
}

int list_remove_front_back(List *list) {
    if (list->size == 0) {
        // list is empty
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 2; i++) {
        list->arr[i] = list->arr[i+2];
    }
    list->size -= 2;
    return 0;
}

int list_remove_front_back_front(List *list) {
    if (list->size < 3) {
        // not enough elements in the list
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 3; i++) {
        list->arr[i] = list->arr[i+3];
    }
    list->size -= 3;
    return 0;
}

int list_remove_front_back_back(List *list) {
    if (list->size < 3) {
        // not enough elements in the list
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 3; i++) {
        list->arr[i] = list->arr[i+2];
    }
    list->size -= 3;
    return 0;
}

int list_remove_front_back_front_back(List *list) {
    if (list->size < 4) {
        // not enough elements in the list
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 4; i++) {
        list->arr[i] = list->arr[i+4];
    }
    list->size -= 4;
    return 0;
}

int list_remove_front_back_back_back(List *list) {
    if (list->size < 4) {
        // not enough elements in the list
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 4; i++) {
        list->arr[i] = list->arr[i+3];
    }
    list->size -= 4;
    return 0;
}

int list_remove_front_back_front_back_back(List *list) {
    if (list->size < 5) {
        // not enough elements in the list
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 5; i++) {
        list->arr[i] = list->arr[i+5];
    }
    list->size -= 5;
    return 0;
}

int list_remove_front_back_back_front_back(List *list) {
    if (list->size < 5) {
        // not enough elements in the list
        return -1;
    }
    int i;
    for (i = 0; i < list->size - 5; i++) {
        list->arr[i] = list->arr[i+4];
    }
    list->size -= 5;
    return 0;
}