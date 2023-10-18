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

    printf("\nList before sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    head = insertionSort(head);

    printf("\nList after sorting:\n");
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
    if (head == NULL || head->next == NULL)
        return head;

    NODEPTR sorted = head;
    NODEPTR curr = head->next;
    sorted->next = NULL;

    while (curr != NULL) {
        NODEPTR temp = curr;
        curr = curr->next;

        if (temp->info < sorted->info) {
            temp->next = sorted;
            sorted = temp;
        } else {
            NODEPTR trav = sorted;
            while (trav->next != NULL && temp->info >= trav->next->info)
                trav = trav->next;
            temp->next = trav->next;
            trav->next = temp;
        }
    }

    return sorted;
}