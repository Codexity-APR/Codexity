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
    if (!head) {
        printf("Memory allocation failed\n");
        return 0;
    }
    head->info = temp;
    head->next = NULL;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        lptr = getnode();
        if (!lptr) {
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
    if (!head) {
        printf("Sorting failed\n");
        return 0;
    }
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }
    printf("\n");
    return 0;
}

NODEPTR getnode() {
    NODEPTR temp = (NODEPTR)malloc(sizeof(struct node));
    return temp;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR lptr, prevlptr, nextlptr;
    int temp;
    if (!head || !head->next) {
        return head;
    }
    for (lptr = head; lptr->next != NULL; lptr = nextlptr) {
        nextlptr = lptr->next;
        if (lptr->info > nextlptr->info) {
            lptr->next = nextlptr->next;
            nextlptr->next = lptr;
            if (lptr == head) {
                head = nextlptr;
                prevlptr = nextlptr;
            } else {
                prevlptr->next = nextlptr;
                prevlptr = nextlptr;
            }
            nextlptr = lptr;
        } else {
            prevlptr = lptr;
        }
    }
    return head;
}