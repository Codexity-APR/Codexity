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
    first->rest = NULL;

    linkedList* second = (linkedList*)malloc(sizeof(linkedList));
    second->first = b;
    second->rest = first;

    linkedList* third = (linkedList*)malloc(sizeof(linkedList));
    third->first = c;
    third->rest = second;

    return third;
}

void addToList(linkedList* ll, int a)
{
    if (ll == NULL) {
        return;
    }

    linkedList* current = ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }

    linkedList* new = (linkedList*)malloc(sizeof(linkedList));
    new->first = a;
    new->rest = NULL;
    current->rest = new;
}