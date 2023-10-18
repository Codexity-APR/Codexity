#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR p, q, r, temp;
    p = head;
    q = NULL;
    while (p != NULL) {
        temp = p;
        p = p->next;
        r = head;
        while (r != NULL && r->info < temp->info) {
            q = r;
            r = r->next;
        }
        if (r == head) {
            temp->next = head;
            head = temp;
        } else {
            temp->next = r;
            q->next = temp;
        }
    }
    return head;
}

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

    printf("\nList before sorting: ");
    for (lptr = head; lptr != NULL; lptr = lptr->next) {
        printf("%d ", lptr->info);
    }

    head = insertionSort(head);

    printf("\nList after sorting: ");
    for (lptr = head; lptr != NULL; lptr = lptr->next) {
        printf("%d ", lptr->info);
    }

    printf("\n");

    return 0;
}