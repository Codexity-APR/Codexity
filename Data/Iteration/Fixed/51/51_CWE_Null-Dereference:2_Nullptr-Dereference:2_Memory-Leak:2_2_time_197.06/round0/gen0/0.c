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

    printf("\nArray before sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    head = insertionSort(head);

    printf("\n\nArray after sorting:\n");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    return 0;
}

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR first, last, curr, temp;
    first = head;
    last = head->next;
    while (last != NULL) {
        curr = first;
        temp = last->next;
        if (last->info < first->info) {
            last->next = first;
            first = last;
        } else {
            while (curr->next != NULL && curr->next->info < last->info) {
                curr = curr->next;
            }
            last->next = curr->next;
            curr->next = last;
        }
        last = temp;
    }
    return first;
}