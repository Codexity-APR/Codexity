#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node** head, int n) {
    node* temp = NULL;
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));
        (*head)->a = n;
        (*head)->next = NULL;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newNode->a = n;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    addSpecific(&head, 5);
    addSpecific(&head, 10);
    addSpecific(&head, 15);
    addSpecific(&head, 20);
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