List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 41 indirectly during the call to `list_new()`in call to `list_add()` .
 Example: 
  41.     List *myList = list_new();
  42. 
  43.     list_add(myList, 10);
          ^
  44.     list_add(myList, 20);
  45.     list_add(myList, 30);

Error: Null Dereference   pointer `list->arr` last assigned on line 21 could be null and is dereferenced at line 24, column 5.
 Example: 
  22.     }
  23. 
  24.     list->arr[list->size] = value;
          ^
  25.     list->size++;
  26. }

Error: Null Dereference   pointer `list` last assigned on line 11 could be null and is dereferenced at line 12, column 5.
 Example: 
  10. List *list_new() {
  11.     List *list = (List *) malloc(sizeof(List));
  12.     list->capacity = 10;
          ^
  13.     list->size = 0;
  14.     list->arr = (int *) malloc(list->capacity * sizeof(int));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 11.
 Example: 
  10. List *list_new() {
  11.     List *list = (List *) malloc(sizeof(List));
  12.     list->capacity = 10;
          ^
  13.     list->size = 0;
  14.     list->arr = (int *) malloc(list->capacity * sizeof(int));


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
    list->arr = (int *) malloc(list->capacity * sizeof(int));
    return list;
}
void list_add(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size] = value;
    list->size++;
}
void list_print(List *list) {
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