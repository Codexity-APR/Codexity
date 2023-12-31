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

    printf("\nBefore sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    head = insertionSort(head);

    printf("\nAfter sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    return 0;
}

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR sortedHead = NULL;
    NODEPTR current = head;
    while (current != NULL) {
        NODEPTR next = current->next;
        if (sortedHead == NULL || current->info < sortedHead->info) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            NODEPTR temp = sortedHead;
            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sortedHead;
}