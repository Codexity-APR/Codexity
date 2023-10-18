#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode();
NODEPTR insertionSort(NODEPTR head);
void displayList(NODEPTR head);

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
    scanf("%d", &temp);
    head->info = temp;
    head->next = NULL;

    lptr = head;

    for (i = 1; i < n; i++) {
        prevlptr = lptr;
        lptr = getnode();
        scanf("%d", &temp);
        lptr->info = temp;
        lptr->next = NULL;
        prevlptr->next = lptr;
    }

    printf("\nInput array: ");
    displayList(head);

    head = insertionSort(head);

    printf("\nSorted array: ");
    displayList(head);

    return 0;
}

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

NODEPTR insertionSort(NODEPTR head) {
    NODEPTR sortedHead = NULL;
    NODEPTR current = head;
    while (current != NULL) {
        NODEPTR next = current->next;
        if (sortedHead == NULL || sortedHead->info >= current->info) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            NODEPTR currentSorted = sortedHead;
            while (currentSorted->next != NULL && currentSorted->next->info < current->info) {
                currentSorted = currentSorted->next;
            }
            current->next = currentSorted->next;
            currentSorted->next = current;
        }
        current = next;
    }
    return sortedHead;
}

void displayList(NODEPTR head) {
    NODEPTR temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}