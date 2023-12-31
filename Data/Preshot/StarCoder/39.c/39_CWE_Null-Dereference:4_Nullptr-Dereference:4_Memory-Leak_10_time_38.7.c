#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int first;
    struct linkedList* rest; // change to struct linkedList*
} linkedList;

linkedList* makeList(int a, int b, int c);
void addToList(linkedList* ll, int a);

int main()
{
    linkedList* ll = makeList(1, 3, 5);
    addToList(ll, 7);
    addToList(ll, 9);
    free(ll->rest->rest->rest);
    free(ll->rest->rest);
    free(ll->rest);
    free(ll);
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
    linkedList* new = (linkedList*)malloc(sizeof(linkedList));
    new->first = a;
    new->rest = NULL;
    linkedList* current = ll;
    while (current->rest!= NULL)
    {
        current = current->rest;
    }
    current->rest = new;
}