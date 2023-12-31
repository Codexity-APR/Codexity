#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int first;
    struct linkedList* rest;
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
    if (first == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    first->first = a;
    first->rest = NULL;
    
    linkedList* second = (linkedList*)malloc(sizeof(linkedList));
    if (second == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    second->first = b;
    second->rest = first;
    
    linkedList* third = (linkedList*)malloc(sizeof(linkedList));
    if (third == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    third->first = c;
    third->rest = second;
    
    return third;
}

void addToList(linkedList** ll, int a)
{
    linkedList* new = (linkedList*)malloc(sizeof(linkedList));
    if (new == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new->first = a;
    new->rest = NULL;
    
    linkedList* current = *ll;
    if (current == NULL) {
        *ll = new;
    }
    else {
        while (current->rest != NULL) {
            current = current->rest;
        }
        current->rest = new;
    }
}