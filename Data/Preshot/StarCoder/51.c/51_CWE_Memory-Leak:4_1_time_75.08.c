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
    NODEPTR i, j, prevj, nexti, previ;
    for (i = head->next; i != NULL; i = nexti) {
        previ = NULL;
        nexti = i->next;
        for (prevj = head, j = head; j != i; prevj = j, j = j->next) {
            if (i->info < j->info) {
                if (previ != NULL) {
                    previ->next = i->next;
                } else {
                    head = i->next;
                }
                if (i == j->next) {
                    j->next = i->next;
                    i->next = j;
                } else {
                    prevj->next = i;
                    i->next = j;
                    previ = i;
                }
                i = prevj;
                break;
            } else {
                previ = j;
            }
        }
    }
    return head;
}