List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 32 indirectly during the call to `list_new()`in call to `list_add()` .
 Example: 
  32.     List *myList = list_new();
  33.     
  34.     list_add(myList, 5);
          ^
  35.     list_add(myList, 10);
  36.     list_add(myList, 15);

Error: Null Dereference   pointer `list->arr` last assigned on line 26 could be null and is dereferenced at line 28, column 5.
 Example: 
  26.         list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
  27.     }
  28.     list->arr[list->size++] = element;
          ^
  29. }
  30.

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
void list_free(List *list) {
    free(list->arr);
    free(list);
}
void list_add(List *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, list->capacity * sizeof(int));
    }
    list->arr[list->size++] = element;
}
int main() {
    List *myList = list_new();
    list_add(myList, 5);
    list_add(myList, 10);
    list_add(myList, 15);
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->arr[i]);
    }
    list_free(myList);
    return 0;
}