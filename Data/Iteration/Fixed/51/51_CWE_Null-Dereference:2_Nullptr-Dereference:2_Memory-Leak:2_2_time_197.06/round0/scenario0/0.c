List of vulnerabilities detected: 
Error: Null Dereference   pointer `lptr` last assigned on line 31 could be null and is dereferenced at line 33, column 9.
 Example: 
  31.         lptr = getnode();
  32.         scanf("%d", &(lptr->info));
  33.         lptr->next = NULL;
              ^
  34.         prevlptr->next = lptr;
  35.         prevlptr = lptr;

Error: Null Dereference   pointer `head` last assigned on line 25 could be null and is dereferenced at line 27, column 5.
 Example: 
  25.     head = getnode();
  26.     scanf("%d", &(head->info));
  27.     head->next = NULL;
          ^
  28.     prevlptr = head;
  29.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 31 indirectly during the call to `getnode()`.
 Example: 
  30.     for (i = 1; i < n; i++) {
  31.         lptr = getnode();
  32.         scanf("%d", &(lptr->info));
              ^
  33.         lptr->next = NULL;
  34.         prevlptr->next = lptr;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25 indirectly during the call to `getnode()`.
 Example: 
  24. 
  25.     head = getnode();
  26.     scanf("%d", &(head->info));
          ^
  27.     head->next = NULL;
  28.     prevlptr = head;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 31 by call to `getnode()`, is not freed after the last access at line 51, column 9.
 Example: 
  49.     while (lptr != NULL) {
  50.         printf("%d ", lptr->info);
  51.         lptr = lptr->next;
              ^
  52.     }
  53.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 25 by call to `getnode()`, is not freed after the last access at line 51, column 9.
 Example: 
  49.     while (lptr != NULL) {
  50.         printf("%d ", lptr->info);
  51.         lptr = lptr->next;
              ^
  52.     }
  53.


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
    head = getnode();
    scanf("%d", &(head->info));
    head->next = NULL;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        lptr = getnode();
        scanf("%d", &(lptr->info));
        lptr->next = NULL;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }
    printf("\nArray before sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    head = insertionSort(head);
    printf("\n\nArray after sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    return 0;
}
NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}
NODEPTR insertionSort(NODEPTR head) {
    NODEPTR first, last, curr, temp;
    first = head;
    last = head->next;
    while (last != NULL) {
        curr = first;
        temp = last->next;
        if (last->info < first->info) {
            last->next = first;
            first = last;
        } else {
            while (curr->next != NULL && curr->next->info < last->info) {
                curr = curr->next;
            }
            last->next = curr->next;
            curr->next = last;
        }
        last = temp;
    }
    return first;
}