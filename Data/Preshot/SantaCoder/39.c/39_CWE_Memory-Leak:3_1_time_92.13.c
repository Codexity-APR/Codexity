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
    if(first == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }
    first->data = a;
    first->next = (linkedList*)malloc(sizeof(linkedList));
    if(first->next == NULL) {
        free(first);
        printf("Memory allocation failed.");
        return NULL;
    }
    first->next->data = b;
    first->next->next = (linkedList*)malloc(sizeof(linkedList));
    if(first->next->next == NULL) {
        free(first->next);
        free(first);
        printf("Memory allocation failed.");
        return NULL;
    }
    first->next->next->data = c;
    first->next->next->next = NULL;
    return first;
}

void addToList(linkedList** ll, int a)
{
    linkedList* node = (linkedList*)malloc(sizeof(linkedList));
    if(node == NULL) {
        printf("Memory allocation failed.");
        return;
    }
    node->data = a;
    node->next = *ll;
    *ll = node;
}