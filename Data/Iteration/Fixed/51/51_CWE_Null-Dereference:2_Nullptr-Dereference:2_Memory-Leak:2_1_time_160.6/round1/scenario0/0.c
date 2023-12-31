List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 37 by call to `getnode()`, is not freed after the last access at line 53, column 9.
 Example: 
  51.     while (lptr != NULL) {
  52.         printf("%d ", lptr->info);
  53.         lptr = lptr->next;
              ^
  54.     }
  55.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 30 by call to `getnode()`, is not freed after the last access at line 53, column 9.
 Example: 
  51.     while (lptr != NULL) {
  52.         printf("%d ", lptr->info);
  53.         lptr = lptr->next;
              ^
  54.     }
  55.


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
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
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