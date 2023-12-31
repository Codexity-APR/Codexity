List of vulnerabilities detected: 
Error: Null Dereference   pointer `lptr` last assigned on line 32 could be null and is dereferenced at line 33, column 9.
 Example: 
  31.         scanf("%d", &temp);
  32.         lptr = getnode();
  33.         lptr->next = NULL;
              ^
  34.         lptr->info = temp;
  35.         prevlptr->next = lptr;

Error: Null Dereference   pointer `head` last assigned on line 25 could be null and is dereferenced at line 26, column 5.
 Example: 
  24.     
  25.     head = getnode();
  26.     head->next = NULL;
          ^
  27.     head->info = temp;
  28.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25 indirectly during the call to `getnode()`.
 Example: 
  24.     
  25.     head = getnode();
  26.     head->next = NULL;
          ^
  27.     head->info = temp;
  28.

 Error type: CWE-457 at line: 27. Error message: Uninitialized variable: temp


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
    p = (NODEPTR) malloc(sizeof(struct node));
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