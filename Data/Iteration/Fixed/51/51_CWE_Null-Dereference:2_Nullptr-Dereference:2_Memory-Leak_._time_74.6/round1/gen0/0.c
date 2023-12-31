#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode();
NODEPTR insertionSort(NODEPTR head);
void freelist(NODEPTR head);

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
            freelist(head);
            return 0;
        }
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

    freelist(head);

    return 0;
}

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    // Implementation of insertion sort
    // ...
    return head;
}

void freelist(NODEPTR head) {
    NODEPTR temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}