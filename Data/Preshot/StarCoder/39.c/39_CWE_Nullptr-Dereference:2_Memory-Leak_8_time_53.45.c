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
    free(ll);
    return 0;
}

linkedList* makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    if(first != NULL){
        first->first = a;
        linkedList* second = (linkedList*)malloc(sizeof(linkedList));
        if(second != NULL){
            second->first = b;
            linkedList* third = (linkedList*)malloc(sizeof(linkedList));
            if(third != NULL){
                third->first = c;
                third->rest = NULL;
                second->rest = third;
                first->rest = second;
                return first;  
            } else {
                free(second);
                free(first);
                return NULL;
            }
        } else {
            free(first);
            return NULL;
        }
    } else {
        return NULL;
    }
}

void addToList(linkedList* ll, int a)
{
    linkedList* new = (linkedList*)malloc(sizeof(linkedList));
    if(new != NULL){
        new->first = a;
        new->rest = NULL;
        linkedList* current = ll;
        while (current->rest!= NULL)
        {
            current = current->rest;
        }
        current->rest = new;
    } else {
        return;
    }
}