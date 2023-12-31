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
    free(ll);
    return 0;
}

linkedList* makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    linkedList* second = (linkedList*)malloc(sizeof(linkedList));
    linkedList* third = (linkedList*)malloc(sizeof(linkedList));
    first->first = a;
    first->rest = second;
    second->first = b;
    second->rest = third;
    third->first = c;
    third->rest = NULL;
    return first;
}

void addToList(linkedList* ll, int a)
{
    linkedList* new = (linkedList*)malloc(sizeof(linkedList));
    new->first = a;
    new->rest = NULL;
    linkedList* current = ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }
    current->rest = new;
}