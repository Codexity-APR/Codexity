List of vulnerabilities detected: 
Error: Null Dereference   pointer `p` last assigned on line 59 could be null and is dereferenced at line 60, column 5.
 Example: 
  58.     NODEPTR p;
  59.     p = (NODEPTR)malloc(sizeof(struct node));
  60.     p->next = NULL;
          ^
  61.     return p;
  62. }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 59.
 Example: 
  58.     NODEPTR p;
  59.     p = (NODEPTR)malloc(sizeof(struct node));
  60.     p->next = NULL;
          ^
  61.     return p;
  62. }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 36 by call to `getnode()`, is not freed after the last access at line 50, column 9.
 Example: 
  48.     while (lptr != NULL) {
  49.         printf("%d ", lptr->info);
  50.         lptr = lptr->next;
              ^
  51.     }
  52.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 29 by call to `getnode()`, is not freed after the last access at line 50, column 9.
 Example: 
  48.     while (lptr != NULL) {
  49.         printf("%d ", lptr->info);
  50.         lptr = lptr->next;
              ^
  51.     }
  52.


#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node* next;
};
typedef struct node* NODEPTR;
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
    head->next = NULL;
    head->info = temp;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        scanf("%d", &temp);
        lptr = getnode();
        lptr->next = NULL;
        lptr->info = temp;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }
    head = insertionSort(head);
    printf("\nSorted array:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    printf("\n");
    return 0;
}
NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    p->next = NULL;
    return p;
}
NODEPTR insertionSort(NODEPTR head) {
    NODEPTR temp, current, sortedHead;
    sortedHead = head;
    head = head->next;
    sortedHead->next = NULL;
    while (head != NULL) {
        current = head;
        head = head->next;
        if (current->info < sortedHead->info) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            temp = sortedHead;
            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    return sortedHead;
}