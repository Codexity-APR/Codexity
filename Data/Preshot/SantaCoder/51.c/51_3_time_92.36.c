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
    head = NULL; // set head to NULL initially
    for (i = 0; i < n; i++) { // loop n times to get n integers
        scanf("%d", &temp);
        lptr = getnode(); // create a new node
        lptr->info = temp; // store integer in the node
        if (head == NULL) { // if head is NULL, set it to the new node
            head = lptr;
            head->next = NULL; // set the next pointer of head to NULL
        }
        else { // if head is not NULL
            prevlptr = NULL; // set prevlptr to NULL
            lptr->next = head; // set the next pointer of the new node to head
            while (head != NULL && head->info <= temp) { // loop until head is NULL or head's info is greater than temp
                prevlptr = head; // set prevlptr to head
                head = head->next; // set head to its next pointer
            }
            if (prevlptr == NULL) { // if prevlptr is still NULL, set head to the new node
                head = lptr;
            }
            else { // if prevlptr is not NULL, set prevlptr's next pointer to the new node
                prevlptr->next = lptr;
            }
            lptr->next = head; // set the next pointer of the new node to head
            head = lptr; // set head to the new node
        }
    }
    insertionSort(head);
    printf("\nSorted array is: ");
    while (head != NULL) { // loop until head is NULL
        printf("%d ", head->info); // print the info part of the node
        head = head->next; // move head to its next pointer
    }
    printf("\n");
    return 0;
}