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
    linkedList* second = (linkedList*)malloc(sizeof(linkedList));
    linkedList* third = (linkedList*)malloc(sizeof(linkedList));
    
    if(first == NULL || second == NULL || third == NULL){
        printf("Error: Memory allocation failed");
        exit(1);
    }
    
    first->first = a;
    first->rest = second;
    
    second->first = b;
    second->rest = third;
    
    third->first = c;
    third->rest = NULL;
    
    return third;
}

void addToList(linkedList* ll, int a)
{
    linkedList* new = (linkedList*)malloc(sizeof(linkedList));
    
    if(new == NULL){
        printf("Error: Memory allocation failed");
        exit(1);
    }
    
    new->first = a;
    new->rest = NULL;
    
    linkedList* current = ll;
    while (current->rest!= NULL)
    {
        current = current->rest;
    }
    current->rest = new;
}