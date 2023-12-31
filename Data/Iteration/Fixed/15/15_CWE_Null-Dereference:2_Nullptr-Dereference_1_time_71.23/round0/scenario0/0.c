List of vulnerabilities detected: 
Error: Null Dereference   pointer `list->arr` last assigned on line 25 could be null and is dereferenced at line 27, column 5.
 Example: 
  25.         list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
  26.     }
  27.     list->arr[list->size] = value;
          ^
  28.     list->size++;
  29. }

Error: Null Dereference   pointer `list` last assigned on line 11 could be null and is dereferenced at line 12, column 5.
 Example: 
  10. List *list_new() {
  11.     List *list = (List *) malloc(sizeof(List));
  12.     list->arr = NULL;
          ^
  13.     list->capacity = 0;
  14.     list->size = 0;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 11.
 Example: 
  10. List *list_new() {
  11.     List *list = (List *) malloc(sizeof(List));
  12.     list->arr = NULL;
          ^
  13.     list->capacity = 0;
  14.     list->size = 0;


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
        if (list->capacity == 0) {
            list->capacity = 1;
        } else {
            list->capacity *= 2;
        }
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value;
    list->size++;
}
void list_print(List *list) {
    printf("List: [");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->arr[i]);
        if (i != list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
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
    list_add(myList, 40);
    list_print(myList);
    list_free(myList);
    return 0;
}