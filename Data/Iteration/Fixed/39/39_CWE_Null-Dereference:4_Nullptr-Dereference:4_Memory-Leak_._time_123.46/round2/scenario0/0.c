List of vulnerabilities detected: 
Error: Null Dereference   pointer `newNode` last assigned on line 51 could be null and is dereferenced at line 52, column 5.
 Example: 
  50. {
  51.     linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
  52.     newNode->first = a;
          ^
  53.     newNode->rest = NULL;
  54.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 51.
 Example: 
  50. {
  51.     linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
  52.     newNode->first = a;
          ^
  53.     newNode->rest = NULL;
  54.

Error: Null Dereference   pointer `third` last assigned on line 39 could be null and is dereferenced at line 40, column 5.
 Example: 
  38. 
  39.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));
  40.     third->first = c;
          ^
  41. 
  42.     first->rest = second;

Error: Null Dereference   pointer `second` last assigned on line 36 could be null and is dereferenced at line 37, column 5.
 Example: 
  35. 
  36.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));
  37.     second->first = b;
          ^
  38. 
  39.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));

Error: Null Dereference   pointer `first` last assigned on line 33 could be null and is dereferenced at line 34, column 5.
 Example: 
  32. {
  33.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  34.     first->first = a;
          ^
  35. 
  36.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 39.
 Example: 
  38. 
  39.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));
  40.     third->first = c;
          ^
  41. 
  42.     first->rest = second;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 36.
 Example: 
  35. 
  36.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));
  37.     second->first = b;
          ^
  38. 
  39.     linkedList* third = (linkedList*)malloc(sizeof(linkedList));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 33.
 Example: 
  32. {
  33.     linkedList* first = (linkedList*)malloc(sizeof(linkedList));
  34.     first->first = a;
          ^
  35. 
  36.     linkedList* second = (linkedList*)malloc(sizeof(linkedList));


#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int first;
    struct linkedList* rest;
} linkedList;
linkedList* makeList(int a, int b, int c);
void addToList(linkedList** ll, int a);
int main()
{
    linkedList* ll = makeList(1, 3, 5);
    addToList(&ll, 7);
    addToList(&ll, 9);
    // Freeing the dynamically allocated memory
    linkedList* current = ll;
    while (current != NULL)
    {
        linkedList* temp = current;
        current = current->rest;
        free(temp);
    }
    return 0;
}
linkedList* makeList(int a, int b, int c)
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
    return first;
}
void addToList(linkedList** ll, int a)
{
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    newNode->first = a;
    newNode->rest = NULL;
    if (*ll == NULL)
    {
        *ll = newNode;
        return;
    }
    linkedList* current = *ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }
    current->rest = newNode;
}