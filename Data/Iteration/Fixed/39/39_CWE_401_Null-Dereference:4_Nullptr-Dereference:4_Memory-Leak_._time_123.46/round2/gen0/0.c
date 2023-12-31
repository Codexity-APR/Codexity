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
    free(ll); // Freeing the allocated memory
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

    linkedList* second = (linkedList*)malloc(sizeof(linkedList));
    if (second == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    second->first = b;

    linkedList* third = (linkedList*)malloc(sizeof(linkedList));
    if (third == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    third->first = c;

    first->rest = second;
    second->rest = third;
    third->rest = NULL;

    return first;
}

void addToList(linkedList* ll, int a)
{
    linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
    if (newElement == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newElement->first = a;
    newElement->rest = NULL;

    linkedList* temp = ll;
    while (temp->rest != NULL)
    {
        temp = temp->rest;
    }
    temp->rest = newElement;
}