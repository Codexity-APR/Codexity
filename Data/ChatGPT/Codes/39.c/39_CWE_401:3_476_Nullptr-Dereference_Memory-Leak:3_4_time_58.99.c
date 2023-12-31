#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int first;
    struct linkedList* rest; // change to struct linkedList*
} linkedList;

linkedList makeList(int a, int b, int c);
void addToList(linkedList* ll, int a);

int main()
{
    linkedList ll = makeList(1, 3, 5);
    addToList(&ll, 7);
    addToList(&ll, 9);
    return 0;
}

linkedList makeList(int a, int b, int c)
{
    linkedList* first = (linkedList*)malloc(sizeof(linkedList));
    
    if (first != NULL)
    {
        first->first = a;
        first->rest = (linkedList*)malloc(sizeof(linkedList));
        
        if (first->rest != NULL)
        {
            first->rest->first = b;
            first->rest->rest = (linkedList*)malloc(sizeof(linkedList));
            
            if (first->rest->rest != NULL)
            {
                first->rest->rest->first = c;
                first->rest->rest->rest = NULL;
            }
            else
            {
                printf("Memory allocation failed");
                return *first;
            }
        }
        else
        {
            printf("Memory allocation failed");
            return *first;
        }
    }
    else
    {
        printf("Memory allocation failed");
        return *first;
    }
    
    return *first;
}

void addToList(linkedList* ll, int a)
{
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    
    if (newNode != NULL)
    {
        newNode->first = a;
        newNode->rest = NULL;
        
        linkedList* current = ll;
        
        while (current->rest != NULL)
        {
            current = current->rest;
        }
        
        current->rest = newNode;
    }
    else
    {
        printf("Memory allocation failed");
    }
}