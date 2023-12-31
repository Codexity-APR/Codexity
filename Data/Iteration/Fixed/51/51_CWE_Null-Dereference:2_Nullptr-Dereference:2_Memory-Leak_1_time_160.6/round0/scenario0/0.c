List of vulnerabilities detected: 
Error: Null Dereference   pointer `lptr` last assigned on line 34 could be null and is dereferenced at line 36, column 9.
 Example: 
  34.         lptr = getnode();
  35.         scanf("%d", &lptr->info);
  36.         lptr->next = NULL;
              ^
  37.         prevlptr->next = lptr;
  38.     }

Error: Null Dereference   pointer `head` last assigned on line 26 could be null and is dereferenced at line 28, column 5.
 Example: 
  26.     head = getnode();
  27.     scanf("%d", &head->info);
  28.     head->next = NULL;
          ^
  29. 
  30.     lptr = head;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 34 indirectly during the call to `getnode()`.
 Example: 
  33.         prevlptr = lptr;
  34.         lptr = getnode();
  35.         scanf("%d", &lptr->info);
              ^
  36.         lptr->next = NULL;
  37.         prevlptr->next = lptr;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 26 indirectly during the call to `getnode()`.
 Example: 
  25. 
  26.     head = getnode();
  27.     scanf("%d", &head->info);
          ^
  28.     head->next = NULL;
  29.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 26 by call to `getnode()`, is not freed after the last access at line 46, column 5.
 Example: 
  44. 
  45.     printf("\nAfter sorting: ");
  46.     printList(head);
          ^
  47. 
  48.     return 0;


#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR getnode();
NODEPTR insertionSort(NODEPTR head);
void printList(NODEPTR head);
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
    lptr = head;
    for (i = 2; i <= n; i++) {
        prevlptr = lptr;
        lptr = getnode();
        scanf("%d", &lptr->info);
        lptr->next = NULL;
        prevlptr->next = lptr;
    }
    printf("Before sorting: ");
    printList(head);
    head = insertionSort(head);
    printf("\nAfter sorting: ");
    printList(head);
    return 0;
}
NODEPTR getnode() {
    return (NODEPTR)malloc(sizeof(struct node));
}
NODEPTR insertionSort(NODEPTR head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    NODEPTR sortedHead = head;
    NODEPTR curr = head->next;
    sortedHead->next = NULL;
    while (curr != NULL) {
        NODEPTR temp = curr;
        curr = curr->next;
        if (temp->info < sortedHead->info) {
            temp->next = sortedHead;
            sortedHead = temp;
        } else {
            NODEPTR currSorted = sortedHead;
            while (currSorted->next != NULL && currSorted->next->info < temp->info) {
                currSorted = currSorted->next;
            }
            temp->next = currSorted->next;
            currSorted->next = temp;
        }
    }
    return sortedHead;
}
void printList(NODEPTR head) {
    NODEPTR temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}