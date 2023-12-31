List of vulnerabilities detected: 
Error: Null Dereference   pointer `prev` last assigned on line 79 could be null and is dereferenced at line 88, column 13.
 Example: 
  86. 
  87.             temp->next = current;
  88.             prev->next = temp;
                  ^
  89.         }
  90.     }

Error: Null Dereference   pointer `lptr` last assigned on line 33 could be null and is dereferenced at line 34, column 9.
 Example: 
  32.         scanf("%d", &temp);
  33.         lptr = getnode();
  34.         lptr->info = temp;
              ^
  35.         lptr->next = NULL;
  36.         prevlptr->next = lptr;

Error: Null Dereference   pointer `head` last assigned on line 26 could be null and is dereferenced at line 27, column 5.
 Example: 
  25. 
  26.     head = getnode();
  27.     head->info = temp;
          ^
  28.     head->next = NULL;
  29.     prevlptr = head;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 79 indirectly during the call to `insertionSort()`in call to `insertionSort()` .
 Example: 
  45.     }
  46. 
  47.     head = insertionSort(head);
                 ^
  48. 
  49.     printf("\nSorted List: ");

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 33 indirectly during the call to `getnode()`.
 Example: 
  32.         scanf("%d", &temp);
  33.         lptr = getnode();
  34.         lptr->info = temp;
              ^
  35.         lptr->next = NULL;
  36.         prevlptr->next = lptr;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 26 indirectly during the call to `getnode()`.
 Example: 
  25. 
  26.     head = getnode();
  27.     head->info = temp;
          ^
  28.     head->next = NULL;
  29.     prevlptr = head;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 33 by call to `getnode()`, is not freed after the last access at line 53, column 9.
 Example: 
  51.     while (lptr != NULL) {
  52.         printf("%d ", lptr->info);
  53.         lptr = lptr->next;
              ^
  54.     }
  55.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 26 by call to `getnode()`, is not freed after the last access at line 53, column 9.
 Example: 
  51.     while (lptr != NULL) {
  52.         printf("%d ", lptr->info);
  53.         lptr = lptr->next;
              ^
  54.     }
  55.

 Error type: CWE-476 at line: 88. Error message: Possible null pointer dereference: prev


#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR getnode();
NODEPTR insertionSort(NODEPTR head);
int main() {
    int i, n, temp;
    NODEPTR head, lptr, prevlptr;
    printf("No of input integers to be sorted\n");
    scanf("%d", &n);
    if (n < 2) {
        printf("n should be at least 2 \n");
        return 0;
    }
    printf("\nType space-separated array of %d integers\n", n);
    scanf("%d", &temp);
    head = getnode();
    head->info = temp;
    head->next = NULL;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        scanf("%d", &temp);
        lptr = getnode();
        lptr->info = temp;
        lptr->next = NULL;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }
    printf("\nOriginal List: ");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    head = insertionSort(head);
    printf("\nSorted List: ");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    return 0;
}
NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}
NODEPTR insertionSort(NODEPTR head) {
    NODEPTR sorted, unsorted, temp;
    sorted = head;
    unsorted = head->next;
    sorted->next = NULL;
    while (unsorted != NULL) {
        temp = unsorted;
        unsorted = unsorted->next;
        if (temp->info < sorted->info) {
            temp->next = sorted;
            sorted = temp;
        } else {
            NODEPTR prev = NULL;
            NODEPTR current = sorted;
            while (current != NULL && temp->info >= current->info) {
                prev = current;
                current = current->next;
            }
            temp->next = current;
            prev->next = temp;
        }
    }
    return sorted;
}