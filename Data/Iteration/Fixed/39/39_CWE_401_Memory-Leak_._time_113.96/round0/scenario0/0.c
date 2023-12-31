List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 23 by call to `malloc`, is not freed after the last access at line 46, column 5.
 Example: 
  44.     first->rest->rest->rest = NULL;
  45.     
  46.     return *first;
          ^
  47. }
  48.

 Error type: CWE-401 at line: 46. Error message: Memory leak: first


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
    if (first == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    first->first = a;
    first->rest = (linkedList*)malloc(sizeof(linkedList));
    if (first->rest == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    first->rest->first = b;
    first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
    if (first->rest->rest == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    first->rest->rest->first = c;
    first->rest->rest->rest = NULL;
    return *first;
}
void addToList(linkedList* ll, int a)
{
    linkedList* lastNode = ll;
    while (lastNode->rest != NULL) {
        lastNode = lastNode->rest;
    }
    lastNode->rest = (linkedList*)malloc(sizeof(linkedList));
    if (lastNode->rest == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    lastNode->rest->first = a;
    lastNode->rest->rest = NULL;
}