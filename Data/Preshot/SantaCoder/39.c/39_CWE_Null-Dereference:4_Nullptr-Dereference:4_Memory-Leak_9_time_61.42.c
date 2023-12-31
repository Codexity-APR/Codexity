#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList* next;
} linkedList;

linkedList* makeList(int a, int b, int c);
void addToList(linkedList** ll, int a);

int main()
{
    linkedList* ll = makeList(1, 3, 5);
    addToList(&ll, 7);
    addToList(&ll, 9);
    return 0;
}

linkedList* makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    first->data = a;
    first->next = (linkedList*)malloc(sizeof(linkedList));
    first->next->data = b;
    first->next->next = (linkedList*)malloc(sizeof(linkedList));
    first->next->next->data = c;
    first->next->next->next = NULL;
    return first;
}

void addToList(linkedList** ll, int a)
{
    linkedList* newnode = (linkedList*)malloc(sizeof(linkedList));
    newnode->data = a;
    newnode->next = *ll;
    *ll = newnode;
}