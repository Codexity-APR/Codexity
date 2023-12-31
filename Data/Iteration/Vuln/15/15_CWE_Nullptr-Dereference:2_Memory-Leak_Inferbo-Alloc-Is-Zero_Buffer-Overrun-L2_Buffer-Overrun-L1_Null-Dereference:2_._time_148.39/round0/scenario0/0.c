List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 21 indirectly during the call to `list_add()`in call to `list_add()` .
 Example: 
  37.     List *myList = list_new();
  38.     
  39.     list_add(myList, 10);
          ^
  40.     list_add(myList, 20);
  41.     list_add(myList, 30);

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 39 by call to `list_add()`, is not freed after the last access at line 40, column 5.
 Example: 
  38.     
  39.     list_add(myList, 10);
  40.     list_add(myList, 20);
          ^
  41.     list_add(myList, 30);
  42.

Error: Inferbo Alloc Is Zero   Length: 0 by call to `list_add`.
 Example: 
  37.     List *myList = list_new();
  38.     
  39.     list_add(myList, 10);
          ^
  40.     list_add(myList, 20);
  41.     list_add(myList, 30);

Error: Buffer Overrun L2   Offset: [0, 2] Size: 1.
 Example: 
  42.     
  43.     for (int i = 0; i < myList->size; i++) {
  44.         printf("%d ", myList->arr[i]);
                            ^
  45.     }
  46.

Error: Buffer Overrun L1   Offset: 2 Size: 1 by call to `list_add`.
 Example: 
  39.     list_add(myList, 10);
  40.     list_add(myList, 20);
  41.     list_add(myList, 30);
          ^
  42.     
  43.     for (int i = 0; i < myList->size; i++) {

Error: Null Dereference   pointer `list->arr` last assigned on line 24 could be null and is dereferenced at line 27, column 5.
 Example: 
  25.     }
  26.     
  27.     list->arr[list->size] = item;
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
void list_add(List *list, int item) {
    if (list->capacity == 0) {
        list->capacity = 1;
        list->arr = (int *) malloc(sizeof(int) * list->capacity);
    } else if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int *) realloc(list->arr, sizeof(int) * list->capacity);
    }
    list->arr[list->size] = item;
    list->size++;
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
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->arr[i]);
    }
    list_free(myList);
    return 0;
}