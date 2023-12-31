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
    NODEPTR head = NULL, lptr = NULL, prevlptr = NULL;
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
        lptr = getnode();
        if (lptr == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }
        scanf("%d", &temp);
        lptr->info = temp;
        lptr->next = NULL;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }
    head = insertionSort(head);
    lptr = head;
    while (lptr!= NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    printf("\n");
    return 0;
}

NODEPTR getnode() {
    NODEPTR temp;
    temp = (NODEPTR)malloc(sizeof(struct node));
    return temp;
}

NODEPTR insertionSort(NODEPTR head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    NODEPTR curr = head;
    NODEPTR prev = NULL;
    while (curr != NULL) {
        NODEPTR temp = curr->next;
        NODEPTR search = head;
        NODEPTR prev_search = NULL;
        while (search != curr) {
            if (curr->info < search->info) {
                if (prev == NULL) {
                    head = curr;
                } else {
                    prev->next = curr;
                }
                curr->next = search;
                if (prev_search == NULL) {
                    head = search;
                } else {
                    prev_search->next = curr;
                }
                NODEPTR swap = search->next;
                search->next = temp;
                curr = swap;
                break;
            } else {
                prev_search = search;
                search = search->next;
            }
        }
        prev = curr;
        curr = temp;
    }
    return head;
}