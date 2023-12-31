List of vulnerabilities detected: 
Error: Null Dereference   pointer `lptr` last assigned on line 34 could be null and is dereferenced at line 35, column 9.
 Example: 
  33.         scanf("%d", &temp);
  34.         lptr = getnode();
  35.         lptr->info = temp;
              ^
  36.         lptr->next = NULL;
  37.         prevlptr->next = lptr;

Error: Null Dereference   pointer `head` last assigned on line 27 could be null and is dereferenced at line 28, column 5.
 Example: 
  26.     scanf("%d", &temp);
  27.     head = getnode();
  28.     head->info = temp;
          ^
  29.     head->next = NULL;
  30.     prevlptr = head;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 34 indirectly during the call to `getnode()`.
 Example: 
  33.         scanf("%d", &temp);
  34.         lptr = getnode();
  35.         lptr->info = temp;
              ^
  36.         lptr->next = NULL;
  37.         prevlptr->next = lptr;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 27 indirectly during the call to `getnode()`.
 Example: 
  26.     scanf("%d", &temp);
  27.     head = getnode();
  28.     head->info = temp;
          ^
  29.     head->next = NULL;
  30.     prevlptr = head;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 34 by call to `getnode()`, is not freed after the last access at line 49, column 9.
 Example: 
  47.     while (lptr != NULL) {
  48.         printf("%d ", lptr->info);
  49.         lptr = lptr->next;
              ^
  50.     }
  51.     printf("\n");

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 27 by call to `getnode()`, is not freed after the last access at line 49, column 9.
 Example: 
  47.     while (lptr != NULL) {
  48.         printf("%d ", lptr->info);
  49.         lptr = lptr->next;
              ^
  50.     }
  51.     printf("\n");


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
    // Create the linked list
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
    // Call the insertion sort function
    head = insertionSort(head);
    // Print the sorted linked list
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
    return p;
}
NODEPTR insertionSort(NODEPTR head) {
    NODEPTR sortedHead, unsortedHead, curr, prev, temp;
    sortedHead = head;
    unsortedHead = head->next;
    sortedHead->next = NULL;
    while (unsortedHead != NULL) {
        curr = unsortedHead;
        unsortedHead = unsortedHead->next;
        if (curr->info < sortedHead->info) {
            curr->next = sortedHead;
            sortedHead = curr;
        } else {
            prev = sortedHead;
            temp = sortedHead->next;
            while (temp != NULL && curr->info > temp->info) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = curr;
            curr->next = temp;
        }
    }
    return sortedHead;
}