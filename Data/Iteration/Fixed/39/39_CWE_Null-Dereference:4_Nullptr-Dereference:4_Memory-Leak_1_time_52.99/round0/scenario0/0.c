List of vulnerabilities detected: 
Error: Null Dereference   pointer `newElement` last assigned on line 35 could be null and is dereferenced at line 36, column 5.
 Example: 
  34. {
  35.     linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
  36.     newElement->first = a;
          ^
  37.     newElement->rest = NULL;
  38.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 35.
 Example: 
  34. {
  35.     linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
  36.     newElement->first = a;
          ^
  37.     newElement->rest = NULL;
  38.

Error: Null Dereference   pointer `first` last assigned on line 23 could be null and is dereferenced at line 24, column 5.
 Example: 
  22. {
  23.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  24.     first->first = a;
          ^
  25.     first->rest = (linkedList*)malloc(sizeof(linkedList));
  26.     first->rest->first = b;

Error: Null Dereference   pointer `first->rest` last assigned on line 25 could be null and is dereferenced at line 26, column 5.
 Example: 
  24.     first->first = a;
  25.     first->rest = (linkedList*)malloc(sizeof(linkedList));
  26.     first->rest->first = b;
          ^
  27.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
  28.     first->rest->rest->first = c;

Error: Null Dereference   pointer `first->rest->rest` last assigned on line 27 could be null and is dereferenced at line 28, column 5.
 Example: 
  26.     first->rest->first = b;
  27.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
  28.     first->rest->rest->first = c;
          ^
  29.     first->rest->rest->rest = NULL;
  30.     return first;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 27.
 Example: 
  26.     first->rest->first = b;
  27.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
  28.     first->rest->rest->first = c;
          ^
  29.     first->rest->rest->rest = NULL;
  30.     return first;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25.
 Example: 
  24.     first->first = a;
  25.     first->rest = (linkedList*)malloc(sizeof(linkedList));
  26.     first->rest->first = b;
          ^
  27.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
  28.     first->rest->rest->first = c;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 23.
 Example: 
  22. {
  23.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  24.     first->first = a;
          ^
  25.     first->rest = (linkedList*)malloc(sizeof(linkedList));
  26.     first->rest->first = b;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 15 by call to `makeList()`, is not freed after the last access at line 17, column 5.
 Example: 
  15.     linkedList* ll = makeList(1, 3, 5);
  16.     addToList(ll, 7);
  17.     addToList(ll, 9);
          ^
  18.     return 0;
  19. }


#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int first;
    struct linkedList* rest;
} linkedList;
linkedList* makeList(int a, int b, int c);
void addToList(linkedList* ll, int a);
int main()
{
    linkedList* ll = makeList(1, 3, 5);
    addToList(ll, 7);
    addToList(ll, 9);
    return 0;
}
linkedList* makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    first->first = a;
    first->rest = (linkedList*)malloc(sizeof(linkedList));
    first->rest->first = b;
    first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
    first->rest->rest->first = c;
    first->rest->rest->rest = NULL;
    return first;
}
void addToList(linkedList* ll, int a)
{
    linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
    newElement->first = a;
    newElement->rest = NULL;
    linkedList* temp = ll;
    while (temp->rest != NULL)
    {
        temp = temp->rest;
    }
    temp->rest = newElement;
}