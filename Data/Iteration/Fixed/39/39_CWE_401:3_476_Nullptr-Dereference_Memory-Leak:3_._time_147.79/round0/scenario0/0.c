List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 23.
 Example: 
  53.     {
  54.         printf("Memory allocation failed");
  55.         return *first;
              ^
  56.     }
  57.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 23 by call to `malloc`, is not freed after the last access at line 58, column 5.
 Example: 
  56.     }
  57.     
  58.     return *first;
          ^
  59. }
  60.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 23 by call to `malloc`, is not freed after the last access at line 49, column 13.
 Example: 
  47.         {
  48.             printf("Memory allocation failed");
  49.             return *first;
                  ^
  50.         }
  51.     }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 23 by call to `malloc`, is not freed after the last access at line 43, column 17.
 Example: 
  41.             {
  42.                 printf("Memory allocation failed");
  43.                 return *first;
                      ^
  44.             }
  45.         }

 Error type: CWE-401 at line: 43. Error message: Memory leak: first

 Error type: CWE-401 at line: 49. Error message: Memory leak: first

 Error type: CWE-401 at line: 58. Error message: Memory leak: first

 Error type: CWE-476 at line: 55. Error message: Either the condition 'first!=NULL' is redundant or there is possible null pointer dereference: first.


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