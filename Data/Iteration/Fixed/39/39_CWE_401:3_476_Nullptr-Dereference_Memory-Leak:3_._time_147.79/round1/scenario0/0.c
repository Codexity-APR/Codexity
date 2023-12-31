List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 15 indirectly during the call to `makeList()`in call to `addToList()` .
 Example: 
  15.     linkedList* ll = makeList(1, 3, 5);
  16.     addToList(ll, 7);
  17.     addToList(ll, 9);
          ^
  18. 
  19.     // Freeing the memory

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 15 indirectly during the call to `makeList()`in call to `addToList()` .
 Example: 
  14. {
  15.     linkedList* ll = makeList(1, 3, 5);
  16.     addToList(ll, 7);
          ^
  17.     addToList(ll, 9);
  18.


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
    // Freeing the memory
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
    if (first != NULL)
    {
        first->first = a;
        first->rest = (linkedList*)malloc(sizeof(linkedList));
        if (first->rest != NULL)
        {
            first->rest->first = b;
            first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
            if (first->rest->rest != NULL)
            {
                first->rest->rest->first = c;
                first->rest->rest->rest = NULL;
            }
            else
            {
                printf("Memory allocation failed");
                free(first->rest);
                free(first);
                return NULL;
            }
        }
        else
        {
            printf("Memory allocation failed");
            free(first);
            return NULL;
        }
    }
    else
    {
        printf("Memory allocation failed");
        return NULL;
    }
    return first;
}
void addToList(linkedList* ll, int a)
{
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    if (newNode != NULL)
    {
        newNode->first = a;
        newNode->rest = NULL;
        linkedList* current = ll;
        while (current->rest != NULL)
        {
            current = current->rest;
        }
        current->rest = newNode;
    }
    else
    {
        printf("Memory allocation failed");
    }
}