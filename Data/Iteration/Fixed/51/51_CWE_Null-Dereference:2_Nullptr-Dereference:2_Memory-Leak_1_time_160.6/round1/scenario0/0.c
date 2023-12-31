List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 29 by call to `getnode()`, is not freed after the last access at line 42, column 13.
 Example: 
  40.         prevlptr = lptr;
  41.         lptr = getnode();
  42.         if (lptr == NULL) {
                  ^
  43.             printf("Memory allocation failed\n");
  44.             return 0;


#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node* next;
};
typedef struct node* NODEPTR;
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
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    scanf("%d", &head->info);
    head->next = NULL;
    lptr = head;
    for (i = 2; i <= n; i++) {
        prevlptr = lptr;
        lptr = getnode();
        if (lptr == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }
        scanf("%d", &lptr->info);
        lptr->next = NULL;
        prevlptr->next = lptr;
    }
    printf("Before sorting: ");
    printList(head);
    head = insertionSort(head);
    printf("\nAfter sorting: ");
    printList(head);
    // Freeing allocated memory
    NODEPTR tempNode;
    while (head != NULL) {
        tempNode = head;
        head = head->next;
        free(tempNode);
    }
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