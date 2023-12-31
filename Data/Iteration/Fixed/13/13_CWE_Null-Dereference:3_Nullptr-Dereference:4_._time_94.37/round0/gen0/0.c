#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    node* temp = NULL;
    if (head->next == NULL) {
        temp = (node*)malloc(sizeof(node));
        head->next = temp;
        temp->a = n;
        temp->next = NULL;
    }
    else {
        temp = (node*)malloc(sizeof(node));
        temp->a = n;
        temp->next = head->next;
        head->next = temp;
    }
}

int main() {
    // Create the head node
    node* head = (node*)malloc(sizeof(node));
    head->a = 0;
    head->next = NULL;

    // Add nodes to the linked list
    addSpecific(head, 1);
    addSpecific(head, 2);
    addSpecific(head, 3);

    // Print the linked list
    node* current = head->next;
    while (current != NULL) {
        printf("%d ", current->a);
        current = current->next;
    }

    // Free memory
    current = head->next;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);

    return 0;
}