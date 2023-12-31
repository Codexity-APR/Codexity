#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    if (head == NULL) {
        printf("Error: Invalid head pointer\n");
        return;
    }

    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    temp->a = n;
    temp->next = head->next;
    head->next = temp;
}

void printList(node* head) {
    if (head == NULL) {
        printf("Error: Invalid head pointer\n");
        return;
    }

    node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    head->next = NULL;
    addSpecific(head, 5);
    addSpecific(head, 3);
    addSpecific(head, 8);

    printf("LinkedList: ");
    printList(head);

    // Freeing the allocated memory
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}