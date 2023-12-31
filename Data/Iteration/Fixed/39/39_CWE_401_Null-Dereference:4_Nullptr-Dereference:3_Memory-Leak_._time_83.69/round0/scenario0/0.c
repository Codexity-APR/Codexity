List of vulnerabilities detected: 
Error: Null Dereference   pointer `current->rest` last assigned on line 44 could be null and is dereferenced at line 45, column 5.
 Example: 
  43. 
  44.     current->rest = (linkedList*)malloc(sizeof(linkedList));
  45.     current->rest->first = a;
          ^
  46.     current->rest->rest = NULL;
  47. }

Error: Null Dereference   pointer `first` last assigned on line 23 could be null and is dereferenced at line 24, column 5.
 Example: 
  22. {
  23.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  24.     first->first = a;
          ^
  25. 
  26.     first->rest = (linkedList*)malloc(sizeof(linkedList));

Error: Null Dereference   pointer `first->rest` last assigned on line 26 could be null and is dereferenced at line 27, column 5.
 Example: 
  25. 
  26.     first->rest = (linkedList*)malloc(sizeof(linkedList));
  27.     first->rest->first = b;
          ^
  28. 
  29.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));

Error: Null Dereference   pointer `first->rest->rest` last assigned on line 29 could be null and is dereferenced at line 30, column 5.
 Example: 
  28. 
  29.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
  30.     first->rest->rest->first = c;
          ^
  31.     first->rest->rest->rest = NULL;
  32.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 29.
 Example: 
  28. 
  29.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
  30.     first->rest->rest->first = c;
          ^
  31.     first->rest->rest->rest = NULL;
  32.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 26.
 Example: 
  25. 
  26.     first->rest = (linkedList*)malloc(sizeof(linkedList));
  27.     first->rest->first = b;
          ^
  28. 
  29.     first->rest->rest = (linkedList*)malloc(sizeof(linkedList));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 23.
 Example: 
  22. {
  23.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  24.     first->first = a;
          ^
  25. 
  26.     first->rest = (linkedList*)malloc(sizeof(linkedList));

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 23 by call to `malloc`, is not freed after the last access at line 33, column 5.
 Example: 
  31.     first->rest->rest->rest = NULL;
  32. 
  33.     return *first;
          ^
  34. }
  35.

 Error type: CWE-401 at line: 33. Error message: Memory leak: first


#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int first;
    struct linkedList* rest;
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
    first->rest = (linkedList*)malloc(sizeof(linkedList));
    first->rest->first = b;
    first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
    first->rest->rest->first = c;
    first->rest->rest->rest = NULL;
    return *first;
}
void addToList(linkedList* ll, int a)
{
    linkedList* current = ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }
    current->rest = (linkedList*)malloc(sizeof(linkedList));
    current->rest->first = a;
    current->rest->rest = NULL;
}