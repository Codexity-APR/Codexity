#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int first;
    struct linkedList* rest;
} linkedList;

linkedList* makeList(int a, int b, int c);
void addToList(linkedList* ll, int a);
void freeList(linkedList* ll);

int main()
{
    linkedList* ll = makeList(1, 3, 5);
    addToList(ll, 7);
    addToList(ll, 9);
    freeList(ll); // Freeing the allocated memory
    return 0;
}

linkedList* makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    if (first == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    first->first = a;
    first->rest = (linkedList*)malloc(sizeof(linkedList));
    if (first->rest == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    first->rest->first = b;
    first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
    if (first->rest->rest == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    first->rest->rest->first = c;
    first->rest->rest->rest = NULL;
    return first;
}

void addToList(linkedList* ll, int a)
{
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->first = a;
    newNode->rest = NULL;
    linkedList* current = ll;
    while (current->rest != NULL)
    {
        current = current->rest;
    }
    current->rest = newNode;
}

void freeList(linkedList* ll)
{
    linkedList* current = ll;
    linkedList* next;
    while (current != NULL)
    {
        next = current->rest;
        free(current);
        current = next;
    }
}