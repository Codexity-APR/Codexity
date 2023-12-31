List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 50 by call to `list_new()`, is not freed after the last access at line 55, column 5.
 Example: 
  53.     }
  54.     list_add(myList, 10);
  55.     list_add(myList, 20);
          ^
  56.     list_add(myList, 30);
  57.     for (int i = 0; i < myList->size; i++) {


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
        return NULL;
    }
    list->arr = (int *) malloc(sizeof(int)); // Allocate memory for arr
    if (list->arr == NULL) {
        free(list);
        return NULL;
    }
    list->capacity = 1;
    list->size = 0;
    return list;
}
void list_add(List *list, int value) {
    if (list == NULL || list->arr == NULL) {
        return;
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        int *newArr = (int *) realloc(list->arr, list->capacity * sizeof(int));
        if (newArr == NULL) {
            return;
        }
        list->arr = newArr;
    }
    list->arr[list->size] = value;
    list->size++;
}
void list_free(List *list) {
    if (list == NULL) {
        return;
    }
    free(list->arr);
    free(list);
}
int main() {
    List *myList = list_new();
    if (myList == NULL) {
        return 1;
    }
    list_add(myList, 10);
    list_add(myList, 20);
    list_add(myList, 30);
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->arr[i]);
    }
    list_free(myList);
    return 0;
}