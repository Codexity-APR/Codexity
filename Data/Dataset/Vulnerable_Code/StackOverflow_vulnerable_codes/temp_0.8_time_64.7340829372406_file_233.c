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
    scanf("%d", &(head->info));
    head->next = NULL;
    prevlptr = head;

    for (i = 1; i < n; i++) {
        lptr = getnode();
        scanf("%d", &(lptr->info));
        lptr->next = NULL;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }

    head = insertionSort(head);

    printf("\nSorted array: ");
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
    NODEPTR sortedHead, current, prevNode, nextNode;

    sortedHead = head;
    current = head->next;
    sortedHead->next = NULL;

    while (current != NULL) {
        nextNode = current->next;

        if (current->info < sortedHead->info) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            prevNode = sortedHead;
            while (prevNode->next != NULL && prevNode->next->info < current->info) {
                prevNode = prevNode->next;
            }
            current->next = prevNode->next;
            prevNode->next = current;
        }

        current = nextNode;
    }

    return sortedHead;
}