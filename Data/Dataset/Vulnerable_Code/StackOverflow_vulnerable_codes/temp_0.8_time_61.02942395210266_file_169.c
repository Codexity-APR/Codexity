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

    // Sort the linked list using insertion sort
    head = insertionSort(head);

    // Print the sorted linked list
    printf("\nSorted array of %d integers: ", n);
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
    NODEPTR sorted = NULL;
    NODEPTR current = head;
    while (current != NULL) {
        NODEPTR next = current->next;
        if (sorted == NULL || current->info < sorted->info) {
            current->next = sorted;
            sorted = current;
        }
        else {
            NODEPTR temp = sorted;
            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}