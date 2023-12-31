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
    if(head == NULL) {
        printf("Memory allocation failed. Exiting..\n");
        return 0;
    }
    head->info = temp;
    head->next = NULL;
    prevlptr = head;
    for (i = 1; i < n; i++) {
        lptr = getnode();
        if(lptr == NULL) {
            printf("Memory allocation failed. Exiting..\n");
            return 0;
        }
        scanf("%d", &temp);
        lptr->info = temp;
        lptr->next = NULL;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }
    head = insertionSort(head);
    if(head == NULL) {
        printf("Memory allocation failed. Exiting..\n");
        return 0;
    }
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
    NODEPTR lptr, prevlptr, nextlptr;
    int temp;
    if(head == NULL || head->next == NULL) {
        return head;
    }
    for(lptr = head->next; lptr != NULL; lptr = lptr->next) {
        prevlptr = lptr->next;
        while(prevlptr != NULL) {
            if(lptr->info > prevlptr->info) {
                temp = lptr->info;
                lptr->info = prevlptr->info;
                prevlptr->info = temp;
            }
            prevlptr = prevlptr->next;
        }
    }
    return head;
}