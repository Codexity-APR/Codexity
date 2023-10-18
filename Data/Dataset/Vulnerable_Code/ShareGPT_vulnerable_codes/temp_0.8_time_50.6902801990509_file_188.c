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
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    list->arr = NULL;
    list->capacity = 0;
    list->size = 0;
    
    return list;
}

void list_add(List *list, int value) {
    if (list->size >= list->capacity) {
        int newCapacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        int *newArr = (int *) realloc(list->arr, newCapacity * sizeof(int));
        
        if (newArr == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        
        list->arr = newArr;
        list->capacity = newCapacity;
    }
    
    list->arr[list->size++] = value;
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
    List *myList = list_new();
    
    list_add(myList, 10);
    list_add(myList, 20);
    list_add(myList, 30);
    
    list_print(myList);
    
    list_free(myList);
    
    return 0;
}