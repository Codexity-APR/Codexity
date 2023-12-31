List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 29 by call to `getnode()`, is not freed after the last access at line 41, column 13.
 Example: 
  39.         scanf("%d", &temp);
  40.         lptr = getnode();
  41.         if (lptr == NULL) {
                  ^
  42.             printf("Memory allocation failed\n");
  43.             return 0;


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
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    head->info = temp;
    head->next = NULL;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        scanf("%d", &temp);
        lptr = getnode();
        if (lptr == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }
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