List of vulnerabilities detected: 
Error: Null Dereference   pointer `myList->arr` last assigned on line 56 could be null and is dereferenced by call to `list_add()` at line 57, column 5.
 Example: 
  55.     }
  56.     list_add(myList, 10);
  57.     list_add(myList, 20);
          ^
  58.     list_add(myList, 30);
  59.     for (int i = 0; i < myList->size; i++) {

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 56 indirectly during the call to `list_add()`in call to `list_add()` .
 Example: 
  55.     }
  56.     list_add(myList, 10);
  57.     list_add(myList, 20);
          ^
  58.     list_add(myList, 30);
  59.     for (int i = 0; i < myList->size; i++) {

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 56 by call to `list_add()`, is not freed after the last access at line 57, column 5.
 Example: 
  55.     }
  56.     list_add(myList, 10);
  57.     list_add(myList, 20);
          ^
  58.     list_add(myList, 30);
  59.     for (int i = 0; i < myList->size; i++) {

Error: Inferbo Alloc Is Zero   Length: 0 by call to `list_add`.
 Example: 
  54.         return 1;
  55.     }
  56.     list_add(myList, 10);
          ^
  57.     list_add(myList, 20);
  58.     list_add(myList, 30);

Error: Buffer Overrun L2   Offset: [0, 2] Size: 1.
 Example: 
  59.     for (int i = 0; i < myList->size; i++) {
  60.         if (myList->arr != NULL && i < myList->size) {
  61.             printf("%d ", myList->arr[i]);
                                ^
  62.         }
  63.     }


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
    list->arr = NULL;
    list->capacity = 0;
    list->size = 0;
    return list;
}
void list_add(List *list, int item) {
    if (list == NULL) {
        return;
    }
    if (list->capacity == 0) {
        list->capacity = 1;
        list->arr = (int *) malloc(sizeof(int) * list->capacity);
        if (list->arr == NULL) {
            return;
        }
    } else if (list->size == list->capacity) {
        list->capacity *= 2;
        int *temp = (int *) realloc(list->arr, sizeof(int) * list->capacity);
        if (temp == NULL) {
            return;
        }
        list->arr = temp;
    }
    list->arr[list->size] = item;
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
        if (myList->arr != NULL && i < myList->size) {
            printf("%d ", myList->arr[i]);
        }
    }
    list_free(myList);
    return 0;
}