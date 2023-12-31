List of vulnerabilities detected: 
Error: Null Dereference   pointer `newElement` last assigned on line 41 could be null and is dereferenced at line 42, column 5.
 Example: 
  40. {
  41.     linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
  42.     newElement->first = a;
          ^
  43.     newElement->rest = NULL;
  44.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 41.
 Example: 
  40. {
  41.     linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
  42.     newElement->first = a;
          ^
  43.     newElement->rest = NULL;
  44.

Error: Null Dereference   pointer `third` last assigned on line 29 could be null and is dereferenced at line 30, column 5.
 Example: 
  28.   
  29.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));
  30.     third->first = c;
          ^
  31.   
  32.     first->rest = second;

Error: Null Dereference   pointer `second` last assigned on line 26 could be null and is dereferenced at line 27, column 5.
 Example: 
  25.   
  26.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));
  27.     second->first = b;
          ^
  28.   
  29.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));

Error: Null Dereference   pointer `first` last assigned on line 23 could be null and is dereferenced at line 24, column 5.
 Example: 
  22. {
  23.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  24.     first->first = a;
          ^
  25.   
  26.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 29.
 Example: 
  28.   
  29.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));
  30.     third->first = c;
          ^
  31.   
  32.     first->rest = second;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 26.
 Example: 
  25.   
  26.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));
  27.     second->first = b;
          ^
  28.   
  29.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 23.
 Example: 
  22. {
  23.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  24.     first->first = a;
          ^
  25.   
  26.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 23 by call to `malloc`, is not freed after the last access at line 36, column 5.
 Example: 
  34.     third->rest = NULL;
  35.   
  36.     return *first;
          ^
  37. }
  38.

 Error type: CWE-401 at line: 36. Error message: Memory leak: first


#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int first;
    struct linkedList* rest; // change to struct linkedList*
} linkedList;
linkedList makeList(int a, int b, int c);
void addToList(linkedList* ll, int a);
int main()
{
    linkedList ll = makeList(1, 3, 5);
    addToList(&ll, 7);
    addToList(&ll, 9);
    return 0;
}
linkedList makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    first->first = a;
    linkedList* second = (linkedList*)malloc(sizeof(linkedList));
    second->first = b;
    linkedList* third = (linkedList*)malloc(sizeof(linkedList));
    third->first = c;
    first->rest = second;
    second->rest = third;
    third->rest = NULL;
    return *first;
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