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
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        temp = head->next;
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
    if (head->next == NULL) {
        printf("List is empty.\n");
    } else {
        node* temp = head->next;
        while (temp != NULL) {
            printf("%d ", temp->a);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;

    // Testing the addSpecific() function
    addSpecific(head, 1);
    addSpecific(head, 2);
    addSpecific(head, 3);

    // Printing the list
    printList(head);

    return 0;
}