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

void addToList(linkedList* ll, int a)
{
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    newNode->first = a;
    newNode->rest = NULL;

    if (ll == NULL)
    {
        ll = newNode;
        return;
    }

    linkedList* current = ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }
    current->rest = newNode;
}