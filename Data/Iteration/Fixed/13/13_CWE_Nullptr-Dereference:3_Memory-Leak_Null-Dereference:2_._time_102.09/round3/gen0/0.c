#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node** head, int n) {
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));
        if (*head == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        (*head)->a = n;
        (*head)->next = NULL;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* new_node = (node*)malloc(sizeof(node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        new_node->a = n;
        new_node->next = NULL;
        temp->next = new_node;
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