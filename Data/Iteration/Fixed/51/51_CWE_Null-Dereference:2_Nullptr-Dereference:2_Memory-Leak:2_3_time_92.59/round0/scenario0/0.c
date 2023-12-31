List of vulnerabilities detected: 
Error: Null Dereference   pointer `lptr` last assigned on line 60 could be null and is dereferenced at line 62, column 9.
 Example: 
  60.         lptr = getnode();
  61.         scanf("%d", &lptr->info);
  62.         lptr->next = NULL;
              ^
  63.         prevlptr->next = lptr;
  64.         prevlptr = lptr;

Error: Null Dereference   pointer `head` last assigned on line 54 could be null and is dereferenced at line 56, column 5.
 Example: 
  54.     head = getnode();
  55.     scanf("%d", &head->info);
  56.     head->next = NULL;
          ^
  57.     prevlptr = head;
  58.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 60 indirectly during the call to `getnode()`.
 Example: 
  59.     for (i = 1; i < n; i++) {
  60.         lptr = getnode();
  61.         scanf("%d", &lptr->info);
              ^
  62.         lptr->next = NULL;
  63.         prevlptr->next = lptr;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 54 indirectly during the call to `getnode()`.
 Example: 
  53. 
  54.     head = getnode();
  55.     scanf("%d", &head->info);
          ^
  56.     head->next = NULL;
  57.     prevlptr = head;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 60 by call to `getnode()`, is not freed after the last access at line 74, column 9.
 Example: 
  72.     while (lptr != NULL) {
  73.         printf("%d ", lptr->info);
  74.         lptr = lptr->next;
              ^
  75.     }
  76.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 54 by call to `getnode()`, is not freed after the last access at line 74, column 9.
 Example: 
  72.     while (lptr != NULL) {
  73.         printf("%d ", lptr->info);
  74.         lptr = lptr->next;
              ^
  75.     }
  76.


#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}
NODEPTR insertionSort(NODEPTR head) {
    NODEPTR p, q, r, temp;
    p = head;
    q = NULL;
    while (p != NULL) {
        temp = p;
        p = p->next;
        if (q == NULL || temp->info < q->info) {
            temp->next = q;
            q = temp;
        } else {
            r = q;
            while (r->next != NULL && r->next->info <= temp->info) {
                r = r->next;
            }
            temp->next = r->next;
            r->next = temp;
        }
    }
    return q;
}
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
    scanf("%d", &head->info);
    head->next = NULL;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        lptr = getnode();
        scanf("%d", &lptr->info);
        lptr->next = NULL;
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
    return 0;
}