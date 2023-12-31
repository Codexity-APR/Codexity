List of vulnerabilities detected: 
Error: Null Dereference   pointer `list->arr` last assigned on line 21 could be null and is dereferenced at line 23, column 5.
 Example: 
  21.         list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
  22.     }
  23.     list->arr[list->size] = element;
          ^
  24.     list->size++;
  25. }

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
void list_add(List *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = element;
    list->size++;
}
void list_print(List *list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->arr[i]);
        if (i != list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
int main() {
    List *list = list_new();
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    list_print(list);
    free(list->arr);
    free(list);
    return 0;
}