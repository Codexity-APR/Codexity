#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node** head, int n) {
    node* temp = *head;
    if (temp == NULL) {
        temp = (node*)malloc(sizeof(node));
        temp->a = n;
        temp->next = NULL;
        *head = temp;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* new_node = (node*)malloc(sizeof(node));
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
    return 0;
}