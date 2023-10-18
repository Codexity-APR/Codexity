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
    first->rest = (linkedList*)malloc(sizeof(linkedList));
  
    linkedList* second = first->rest;
    second->first = b;
    second->rest = (linkedList*)malloc(sizeof(linkedList));
  
    linkedList* third = second->rest;
    third->first = c;
    third->rest = NULL;
  
    return *first;
}

void addToList(linkedList* ll, int a)
{
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    newNode->first = a;
    newNode->rest = NULL;

    linkedList* current = ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }
    current->rest = newNode;
}