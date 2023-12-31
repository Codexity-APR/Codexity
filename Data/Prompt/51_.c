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
    scanf("%d", &temp);

    head = getnode();
