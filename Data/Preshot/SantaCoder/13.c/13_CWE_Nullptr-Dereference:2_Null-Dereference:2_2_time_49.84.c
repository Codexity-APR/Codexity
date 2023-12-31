#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node** head, int n) {
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));
        (*head)->next = NULL;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    for (int i = 0; i < n; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->a = i;
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }
}

int main() {
    node* head = NULL;
    int n = 10;
    addSpecific(&head, n);
    return 0;
}