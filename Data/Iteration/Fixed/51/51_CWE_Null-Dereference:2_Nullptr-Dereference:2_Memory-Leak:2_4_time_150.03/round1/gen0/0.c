#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

typedef struct node* NODEPTR;

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
            return 0;
        }
        lptr->info = temp;
        lptr->next = NULL;
        prevlptr->next = lptr;
        prevlptr = lptr;
    }

    printf("\nOriginal array: ");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    head = insertionSort(head);

    printf("\nSorted array: ");
    lptr = head;
    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    // Freeing the allocated memory
    lptr = head;
    while (lptr != NULL) {
        NODEPTR temp = lptr;
        lptr = lptr->next;
        free(temp);
    }

    return 0;
}

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR sortedList = NULL;
    NODEPTR current = head;

    while (current != NULL) {
        NODEPTR next = current->next;

        if (sortedList == NULL || current->info < sortedList->info) {
            current->next = sortedList;
            sortedList = current;
        } else {
            NODEPTR searchNode = sortedList;

            while (searchNode->next != NULL && searchNode->next->info < current->info) {
                searchNode = searchNode->next;
            }

            current->next = searchNode->next;
            searchNode->next = current;
        }

        current = next;
    }

    return sortedList;
}