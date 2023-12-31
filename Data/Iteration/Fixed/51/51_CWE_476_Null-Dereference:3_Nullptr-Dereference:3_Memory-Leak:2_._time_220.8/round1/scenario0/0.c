List of vulnerabilities detected: 
Error: Null Dereference   pointer `lptr` last assigned on line 36 could be null and is dereferenced at line 37, column 9.
 Example: 
  35.         scanf("%d", &temp);
  36.         lptr = getnode();
  37.         lptr->info = temp;
              ^
  38.         lptr->next = NULL;
  39.         prevlptr->next = lptr;

Error: Null Dereference   pointer `head` last assigned on line 29 could be null and is dereferenced at line 30, column 5.
 Example: 
  28. 
  29.     head = getnode();
  30.     head->info = temp;
          ^
  31.     head->next = NULL;
  32.     prevlptr = head;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 36 indirectly during the call to `getnode()`.
 Example: 
  35.         scanf("%d", &temp);
  36.         lptr = getnode();
  37.         lptr->info = temp;
              ^
  38.         lptr->next = NULL;
  39.         prevlptr->next = lptr;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 29 indirectly during the call to `getnode()`.
 Example: 
  28. 
  29.     head = getnode();
  30.     head->info = temp;
          ^
  31.     head->next = NULL;
  32.     prevlptr = head;


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
    // Freeing the memory
    lptr = head;
    while (lptr != NULL) {
        NODEPTR temp = lptr;
        lptr = lptr->next;
        free(temp);
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
            if (prev != NULL) {
                temp->next = current;
                prev->next = temp;
            } else {
                temp->next = sorted;
                sorted = temp;
            }
        }
    }
    return sorted;
}