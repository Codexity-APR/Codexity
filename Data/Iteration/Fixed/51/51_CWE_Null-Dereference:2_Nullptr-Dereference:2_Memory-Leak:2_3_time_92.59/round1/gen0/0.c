#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

typedef struct node* NODEPTR;

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
    NODEPTR p, q, r, temp;
    p = head;
    q = NULL;
    while (p != NULL) {
        temp = p;
        p = p->next;
        if (q == NULL || temp->info < q->info) {
            temp->next = q;
            q = temp;
        } else {
            r = q;
            while (r->next != NULL && r->next->info <= temp->info) {
                r = r->next;
            }
            temp->next = r->next;
            r->next = temp;
        }
    }
    return q;
}

int main() {
    int i, n, temp;
    NODEPTR head, lptr, prevlptr;
    printf("No of input integers to be sorted: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("n should be at least 2\n");
        return 0;
    }
    printf("\nType space-separated array of %d integers: ", n);
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
    head = insertionSort(head);
    printf("\nSorted array:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    printf("\n");

    // Freeing the allocated memory
    lptr = head;
    while (lptr != NULL) {
        NODEPTR temp = lptr;
        lptr = lptr->next;
        free(temp);
    }

    return 0;
}