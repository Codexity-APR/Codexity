#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} List;

List *list_new() {
    List *list = malloc(sizeof(List));
    if (list != NULL) {
        list->arr = NULL;
        list->capacity = 0;
        list->size = 0;
    }
    return list;
}

void list_add(List *list, int val) {
    if (list == NULL) {
        fprintf(stderr, "Error: NULL List pointer.\n");
        return;
    }
    if (list->size == list->capacity) {
        if (list->capacity == 0) {
            list->capacity = 1;
        } else {
            list->capacity *= 2;
        }
        int *new_arr = realloc(list->arr, list->capacity * sizeof(int));
        if (new_arr == NULL) {
            fprintf(stderr, "Error: Out of memory.\n");
            return;
        }
        list->arr = new_arr;
    }
    list->arr[list->size++] = val;
}

int list_get(List *list, int index) {
    if (list == NULL) {
        fprintf(stderr, "Error: NULL List pointer.\n");
        return -1;
    }
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: Index out of range.\n");
        return -1;
    }
    return list->arr[index];
}

void list_free(List *list) {
    if (list == NULL) {
        fprintf(stderr, "Error: NULL List pointer.\n");
        return;
    }
    free(list->arr);
    free(list);
    list = NULL;
}

int main(int argc, char *argv[]) {
    List *list = list_new();
    if (list == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return -1;
    }
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    printf("%d\n", list_get(list, 1));
    list_free(list);
    return 0;
}