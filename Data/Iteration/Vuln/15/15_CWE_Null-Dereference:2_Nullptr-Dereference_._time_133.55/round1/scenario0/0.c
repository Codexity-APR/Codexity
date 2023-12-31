List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 46 indirectly during the call to `list_new()`in call to `list_add()` .
 Example: 
  49.     }
  50.     list_add(myList, 10);
  51.     list_add(myList, 20);
          ^
  52.     list_add(myList, 30);
  53.     for (int i = 0; i < myList->size; i++) {


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
void list_add(List *list, int value) {
    if (list == NULL) {
        return;
    }
    if (list->size == list->capacity) {
        list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
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