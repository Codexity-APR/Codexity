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
        lptr = getnode();
        scanf("%d", &temp);
        lptr->info = temp;
        lptr->next = NULL;
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

    return 0;
}

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR currNode, nextNode, sortedList;
    sortedList = getnode();
    sortedList->info = head->info;
    sortedList->next = NULL;
    currNode = head->next;

    while (currNode != NULL) {
        nextNode = currNode->next;
        if (currNode->info < sortedList->info) {
            currNode->next = sortedList;
            sortedList = currNode;
        } else {
            NODEPTR temp = sortedList;
            while (temp->next != NULL && currNode->info > temp->next->info) {
                temp = temp->next;
            }
            currNode->next = temp->next;
            temp->next = currNode;
        }
        currNode = nextNode;
    }

    return sortedList;
}