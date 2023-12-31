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

    head = getnode();

    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    lptr = head;

    for (i = 1; i < n; i++) {
        scanf("%d", &temp);

        lptr->next = getnode();

        if (lptr->next == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }

        lptr = lptr->next;
        lptr->info = temp;
        lptr->next = NULL;
    }

    printf("\nUnsorted List: ");
    lptr = head;

    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    head = insertionSort(head);

    printf("\nSorted List: ");
    lptr = head;

    while (lptr != NULL) {
        printf("%d ", lptr->info);
        lptr = lptr->next;
    }

    // Freeing the dynamically allocated memory
    lptr = head;

    while (lptr != NULL) {
        NODEPTR temp = lptr;
        lptr = lptr->next;
        free(temp);
    }

    printf("\n");

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
            NODEPTR temp = sortedList;

            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sortedList;
}